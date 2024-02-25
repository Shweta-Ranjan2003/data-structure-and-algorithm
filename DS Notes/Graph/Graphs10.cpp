#include <iostream>
#include <vector>
using namespace std;
class DisjointSet {
public:
    vector<int> rank, parent,size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/*
Maximum Stone Removal
Most Stones Removed with Same Row or Column - DSU
In every connected component i can remove n-1 stones

if there are n=5 components
x1 x2 x3 x4 x5
then most stone that can be removed is
x1-1 x2-1 x3-1 x4-1 x5-1
(x1+x2+x3+x4+x5)-(1+1+1+1+1)
ans= n            -  no. of components

Watch video 53 (take u forward graph) for explaination

int maxRemove(vector<vector<int>>&stones,int n){
    int maxRow=0;
    int maxCol=0;
    for(auto it:stones){
        maxRow=max(maxRow,it[0]);
        maxCol=max(maxCol,it[i]);
    }
    DisjointSet ds(maxRow+maxCol+1);
    unordered_map<int,int>stoneNodes;
    //We just need the nodes in Disjoint Set which are involved in having a stone.
    //So we store the rows and coloumns in map as they will have stones. 
    //And we just need to count them once for ultimate parents.

    for(auto it:stones){
        int nodeRow=it[0];
        int nodeCol=it[1]+maxRow+1;
        ds.unionBySize(nodeRow,nodeCol);
        stoneNodes[nodeRow]=1;
        stoneNodes[nodeCol]=1;
    }
    int cnt=0;
    for(auto it: stoneNodes){
        if(ds.findUPar(it.first)==it.first){
            cnt++;
        }
    }
    return n-cnt;
}
*/

/*
*****Kosaraju's Algorithm******
Strongly Connected Components - Valid for Directed Graph
SCC are in which every node can reach any other node

1. Sort all the edges according to the finishing time
2. Reverse the graph
3. do a dfs

When you will reverse the graph you will not be able to go the scc1 from 2 or from 3 to 2
but we can to scc1 from when graph was not reversed . so this is a check of scc

 void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
*/

/*
Bridges in Graph - Tarjan's Algorithm of time in and low time
Any edge when broken down and then graph is broked into 2 component is a bridge

1. tm[]= DFS time of insertion
2. low[] =min lowest time of insertion of all adjacent nodes apart from parent

Critical connections
 int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
*/

/*
Articulation Points
Nodes on whose removal the graph breaks into multiple components.

tin[] = store the time of insertion during dfs
low[] = min of all adjacent nodes apart from parent and visited nodes

int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
*/
int main()
{ 
 
 return 0;
}