#include <bits/stdc++.h>
using namespace std;
/*
Checking Existence of Edge Length Limited Paths
*/
class Solution {
public:
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
            rank[y_parent]++;
        }
    }

    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i<n; i++)
            parent[i] = i;
        
        
        for(int i = 0; i<queries.size(); i++) {
            queries[i].push_back(i);
        }
        
        
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };

        sort(begin(edgeList), end(edgeList), lambda);
        sort(begin(queries),  end(queries),  lambda);
        
        vector<bool> result(queries.size());
        
        int j = 0;
        for(vector<int>& query : queries) {
            
            int u   = query[0];
            int v   = query[1];
            int w   = query[2];
            int idx = query[3];
            
            while(j < edgeList.size() && edgeList[j][2] < w) {
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            
            result[idx] = find(u) == find(v);
            
        }
        
        return result;
        
    }
};

/*
1557. Minimum Number of Vertices to Reach All Nodes
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
*/
 vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0),ans;
        for(auto e:edges) indegree[e[1]]++;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)ans.push_back(i);
        return ans;
    }

/*
1091. Shortest Path in Binary Matrix
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n=grid.size();
       if(n==1 and grid[0][0]==0)return 1;
       if(grid[0][0]==1)return -1;
       queue<pair<int,pair<int,int>>>q;
       //dist,row,col
       q.push({1,{0,0}}); 
       int delr[]={-1,-1,-1,0,0,1,1,1};
       int delc[]={-1,0,1,-1,1,-1,0,1};
       vector<vector<int>>dist(n,vector<int>(n,1e9));
       dist[0][0]=0;
       while(!q.empty()){
           auto it=q.front();
           int distnode=it.first;
           int row=it.second.first;
           int col=it.second.second;
           q.pop();
           for(int i=0;i<8;i++){
               int newrow=row+delr[i];
               int newcol=col+delc[i];
            if(newrow>=0 and newrow<n and newcol>=0 and newcol<n and grid[newrow][newcol]==0 and distnode+1<dist[newrow][newcol]){
                    dist[newrow][newcol]=distnode+1;
                    if(newrow==n-1 and newcol==n-1)return distnode+1;
                    q.push({distnode+1,{newrow,newcol}});
            }
           }
       }
       return -1;
    }

int main()
{ 
 
 return 0;
}