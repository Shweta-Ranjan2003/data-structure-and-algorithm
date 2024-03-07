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

/*
2092. Find All People With Secret
You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

 

Example 1:

Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
Example 2:

Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
Output: [0,1,3]
Explanation:
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
Example 3:

Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
*/

class UnionFind {    
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x]) return x;
        else return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)  return;
        if (rank[rX] > rank[rY]) swap(rX, rY);   
        root[rX] = rY;
        if (rank[rX]==rank[rY]) rank[rY]++;
    }
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }

    void reset(int x){//very useful for removing edges
        root[x]=x;
        rank[x]=1;
    }
};

class Solution {
public:
    using int2=pair<int, int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        //1 <= time_i <= 10^5, Counting sort is suitable
        vector<int2> meet_time[100001];//meet_time[t] = {(x,y) has meeting at t}
        int tMax=-1;
        for(auto& meet: meetings){
            int x=meet[0], y=meet[1], t=meet[2];
            meet_time[t].emplace_back(x, y);// 1 pair is enough
           // meet_time[t].emplace_back(y, x);
            tMax=max(tMax, t);
        }
        UnionFind uf(n);
        uf.Union(0, firstPerson);// add edge (0, firstPerson)
        for (int t=0; t<=tMax; t++){
            for(auto& [x, y]: meet_time[t])
                uf.Union(x, y);
            for(auto& [x, y]: meet_time[t]){//Important part
                if (!uf.connected(0, x)){
                    //If x is not connected to 0, remove the edge
                    uf.reset(x);
                    uf.reset(y);
                }
            }
        }
        vector<int> list={0};
        for(int i=1; i<n; i++)
            if (uf.connected(0, i)) list.push_back(i);

        return list;
    }
int main()
{ 
 
 return 0;
}