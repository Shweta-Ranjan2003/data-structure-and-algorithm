#include <bits/std++.h>
using namespace std;
/*
2421. Number of Good Paths
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.
Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
*/
vector<int> parent;
    vector<int> rank;
    
    int find (int x) {
        if (x == parent[x]) 
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        
        if (x_parent == y_parent) 
            return;
        
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        parent.resize(n);
        rank.resize(n, 1);
        
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        map<int, vector<int>> val_to_nodes;
        
        for (int i = 0; i < n; i++) {
            int value = vals[i];
            
            val_to_nodes[value].push_back(i);
        }
        
        int result = n;
        
        vector<bool> is_active(n, false); //non active in the beginning
        
        for (auto &it : val_to_nodes) {
            
            vector<int> nodes = it.second;
            
            for (int &u : nodes) {
                
                for (int &v: adj[u]) {
                    if (is_active[v]) {
                        Union(u, v);
                    }
                }
                is_active[u] = true;
            }
            
            vector<int> tumhare_parents;
            
            for (int &u : nodes) 
                tumhare_parents.push_back(find(u));
            
            sort(tumhare_parents.begin(), tumhare_parents.end());
                        
            int sz = tumhare_parents.size();
            
            for (int j = 0; j < sz; j++) {
                long long count = 0;
                
                int cur_parent = tumhare_parents[j];
                
                while (j < sz && tumhare_parents[j] == cur_parent) {
                    j++, 
                    count++;
                }
                j--;
                
                result += (count * (count - 1))/2;
            }
        }
        
        return result;
    }
int main()
{ 
 
 return 0;
}