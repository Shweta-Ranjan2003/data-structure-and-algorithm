/*
Connected Cities
You are given n cities represented as an integer in [0, n) and a list of one-way roads that connect one city to another.

Return whether you can reach any city from any city.

Constraints

n ≤ 10,000

m ≤ 100,000 where m is the length of roads

Example:

Input

n = 2
roads = [
    [0, 1],
    [1, 0]
]
Output

true
Explanation

You can go 0 to 1 and 1 to 0
*/
#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],vector<int>&vis){
    vis[node]=1;
    int size=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            size+=dfs(it,adj,vis);
        }
    }
    return size;
}
bool solve(int n, vector<vector<int>> roads) {
    vector<int>adj[n];
    for(auto it:roads){
        adj[it[0]].push_back(it[1]);
    }
    for(int i=0;i<n;i++){
    vector<int>vis(n,0);
        if(dfs(i,adj,vis)!=n){
            return false;
        }
    }
    return true;
}

//Or use dfs to check if all the nodes are present in one component
//Then use kosaraju to check if they are strongly connected or not

/*
Make Network Connected
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a 
network where connections[i] = [a, b] represents a connection between computers a and b. 
Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly 
connected computers, and place them between any pair of disconnected computers to make them directly connected. 
Return the minimum number of times you need to do this in order to make all the computers connected. 
If it's not possible, return -1.
*/
class DisjointSet{
    public:
    vector<int>parent,sizee;
    DisjointSet(int n){
        parent.resize(n+1);
        sizee.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            sizee[i]=1;
        }
    }
    int FindUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=FindUPar(parent[node]);
    }
    int UnionBySize(int u,int v){
        int ulp_u=FindUPar(u);
        int ulp_v=FindUPar(v);
        if(ulp_u==ulp_v){
            return 1;
        }
        if(sizee[ulp_u]<sizee[ulp_v]){
            parent[ulp_u]=ulp_v;
            sizee[ulp_v]+=sizee[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            sizee[ulp_u]+=sizee[ulp_v];
        }
        return 0;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extras=0;
        DisjointSet ds(n);
        int m=connections.size();
        for(int i=0;i<m;i++){ 
           extras+=ds.UnionBySize(connections[i][0],connections[i][1]);
        }
        int component=0;
        set<int> s;
        for(int i=0;i<n;i++) {
            if(s.find(ds.FindUPar(i)) == s.end()) {
                component++;
                s.insert(ds.FindUPar(i));
            }
        }
        if((s.size()-1) <= extras) {
            return s.size()-1;
        }
        return -1;
    }
};

/*
Delay Time in Network
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times 
as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is 
the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.
*/
 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>{} );
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();

            for(auto x:adj[node]){
                int adjNode=x.first;
                int adjDist=x.second;
                if(dis+adjDist < dist[adjNode]){
                    dist[adjNode]=dis+adjDist;
                    pq.push({adjDist+dis,adjNode});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==1e9){return -1;}
        return ans;
    }