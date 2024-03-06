#include <bits/stdc++.h>
using namespace std;
/*
886. Possible Bipartition
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
*/
bool isBipartite(unordered_map<int, vector<int>> &adj, int node, vector<int>& color) {
        queue<int> que;
        
        que.push(node);
        color[node] = 1;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                if(color[v] == color[u])
                    return false;
                
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> &vec : dislikes) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1, -1);
        
        for(int i = 1; i<=n; i++) {
            if(color[i] == -1) {
                if(!isBipartite(adj, i, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }

/*
834. Sum of Distances in Tree
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
*/
long result_base_node = 0;
    vector<int> count;
    int N;
    int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        
        result_base_node += curr_depth;
        
        for(int &child : adj[curr_node]) {
            if(child == prev_node)
                continue;
            
            total_node += dfsBase(adj, child, curr_node, curr_depth+1);
        }
        
        //store count of subtrees of each node
        count[curr_node] = total_node;
        
        return total_node;
    }
    
    void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>& result) {
        
        for(int &child : adj[parent_node]) {
            if(child == prev_node)
                continue;
            
            result[child] = result[parent_node] - count[child] + (N - count[child]);
            DFS(adj, child, parent_node, result);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        result_base_node = 0;
        
        dfsBase(adj, 0, -1, 0);
        
        vector<int> result(n, 0);
        
        result[0] = result_base_node;
        
        DFS(adj, 0, -1, result);
        
        return result;
    }

/*
2492. Minimum Score of a Path Between Two Cities
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
*/
void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int u, vector<bool>& visited, int &result) {
        
        visited[u] = true;
        
        for(auto &vec : adj[u]) {
            int v = vec.first;
            int c = vec.second;
            
            result = min(result, c);
            
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : roads) {
            
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<bool> visited(n, false);
        int result = INT_MAX;
        dfs(adj, 1, visited, result);
        
        return result;
    }
int main()
{ 
 
 return 0;
}