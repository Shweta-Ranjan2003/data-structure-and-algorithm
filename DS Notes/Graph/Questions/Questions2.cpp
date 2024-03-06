/*
Subtree Problem
You are given a tree with n nodes rooted at 1  where each node is numbered 1 to n.

The tree is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi , and also you are given an array of queries where query[i] = ui , you have to count the number of nodes present in the subtree of  node ui for each query.

Return an array containing the answer of each query respectively.

Constraints:

2≤ n ≤10^5

1<= edges.length <= n-1

1≤ queries.length ≤10^5

1<= ui, vi <=n

Example:

Input

n = 5
edges = [
    [1, 2],
    [1, 3],
    [3, 4],
    [3, 5]
]
 
queries = [ 1, 2, 3, 4, 5]
Output

[5, 1, 3, 1, 1]
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],int&count){
    count++;
    for(auto it:adj[node]){
        dfs(it,adj,count);
    }
}
vector<int> subtreeProblem (int n, vector<vector<int>> edges, vector<int> queries)
{
    vector<int>adj[n+1];
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
    }
    int m=queries.size();
    vector<int>ans;
    for(int i=0;i<m;i++){
        int count=0;
        dfs(queries[i],adj,count);
        ans.push_back(count);
    }
    return ans;
}

/*
Message Route
There is a network of n computers, each computer is numbered 1 to n.

The computer network is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge that connects computer ui and computer vi .

Your task is to find if Alice can send a message to Bob, if it is possible, return minimum number of computers on such a route and if it is not possible than return -1.

Alice's Computer is 1 and Bob's computer is  n.

Constraints:

2≤ n ≤10^5

1<= edges.length <= 2*10^5

1<= ui, vi <=n

Example:

Input: n= 5, edges= [[1,2],[1,3],[1,4],[2,3],[5,4]] 
 
Output: 3
*/
#include<bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>>edges){
    vector<int>adj[n+1];
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n+1,INT_MAX);
    dist[1]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({1,1});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int distance=it.first;
        int node=it.second;
        for(auto it:adj[node]){
            if(distance+1<dist[it]){
                dist[it]=1+distance;
                pq.push({dist[it],it});
            }
        }
    }
    return dist[n];
}

/*
Tree Distances
You are given a tree with n nodes where each node has labels in the set {1,2,.......,n} .

The tree is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi , you have to return for each node the maximum distance to any another node.

Return an array containing the answer of each node from  1 to n  respectively.

Constraints:

1≤ n ≤10^5

0<= edges.length <= n-1



Example:

Input

n = 5
edges = [
    [1, 2],
    [1, 3],
    [3, 4],
    [3, 5]
]
Output

[2, 3, 2, 3, 3]
*/

#include<bits/stdc++.h>
using namespace std;

int bfs(int node,vector<int> graph[]) {
    int size=-1;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(!q.empty()){
        size++;
        int n=q.size();
        for(int i=0;i<n;i++){
        auto it= q.front();
        int node=it.first;
        int parent=it.second;
        q.pop();
        for(auto it:graph[node]){
            if(it!=parent){
                q.push({it,node});
            }
        }
        }
    }
    return size;
}
vector<int> treeDistances(int n, vector<vector<int>>edges)
{
    vector<int> graph[n+1];
    for (auto it : edges) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        int cnt=bfs(i,graph);
        ans.push_back(cnt);
    }
    return ans;
}