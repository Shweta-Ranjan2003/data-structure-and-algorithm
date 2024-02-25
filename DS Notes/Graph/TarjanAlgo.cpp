#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Bridges in Graph
//1192. Critical Connections in a Network
//tin - time of insertion
/*
int timer=1;
void dfs(int node , int parent,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(!vis[it]){
            dfs(it,node,vis,adj,tin,low,bridges);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                bridges.push_back({it,node});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}
vector<vector<int>> critical(int n,vector<vector<int>>&connections){
    vector<int>adj[n];
    for(auto it: connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n,0);
    int tin[n];
    int low[n];
    vector<vector<int>>bridges;
    dfs(0,-1,vis,adj,tin,low,bridges);
    return bridges;
} 
*/



//Articulation point gfg
int timer=1;
  void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,int tin[],int low[],vector<int>&mark){
      vis[node]=1;
      tin[node]=low[node]=timer;
      timer++;
      int child=0;
      for(auto it:adj[node]){
          if(it==parent)continue;
          if(!vis[it]){
              dfs(it,node,adj,vis,tin,low,mark);
              low[node]=min(low[node],low[it]);
              if(low[it]>=tin[node] and parent!=-1){
                  mark[node]=1;
              }
              child++;
          }
          else{
              low[node]=min(low[node],tin[it]);
          }
      }
      if(child>1 and parent==-1) mark[node]=1;
  }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,tin,low,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
int main()
{ 
 
 return 0;
}