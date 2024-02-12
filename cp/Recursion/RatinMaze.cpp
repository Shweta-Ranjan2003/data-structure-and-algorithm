#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Rat in a Maze Problem - I - GFG

Rat in a maze - no of ways to reach the cheese by rat if he can move in 4 directions
                but cannot revisit a cell in the same path to avoid infinite loop
*/
int delr[4]={-1,0,0,1};
    int delc[4]={0,-1,1,0};
    void recur(int i,int j,int n,vector<vector<int>>&maze,vector<vector<int>>&vis,
               string&ds,vector<string>&ans){
        if(i>=n || j>=n || i<0 || j<0)return;
        if(i==n-1 && j==n-1){
            ans.push_back(ds);
            return;}
        
        for(int k=0;k<4;k++){
            int row=i+delr[k];
            int col=j+delc[k];
            if(row<n && row>=0 && col<n && col>=0 && maze[row][col]==1 &&vis[row][col]==0){
                
                if(delr[k]==-1 and delc[k]==0)ds.push_back('U');
                else if(delr[k]==0 and delc[k]==-1)ds.push_back('L');
                else if(delr[k]==0 and delc[k]==1)ds.push_back('R');
                else if(delr[k]==1 and delc[k]==0)ds.push_back('D');
                
                vis[row][col]=1;
                recur(row,col,n,maze,vis,ds,ans);
                ds.pop_back();
                vis[row][col]=0;
            }
        }
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        vis[0][0]=1;
        string ds="";
        vector<string>ans;
        if(m[0][0]==0)return ans;
        if(m[n-1][n-1]==0)return ans;
        recur(0,0,n,m,vis,ds,ans);
        return ans;
    }
int main()
{ 
    vector<vector<int>>maze{{1,1,1},
                            {0,1,1},
                            {0,0,1}};
    int n=maze.size();
    vector<string> ans=findPath(maze,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
 return 0;
}