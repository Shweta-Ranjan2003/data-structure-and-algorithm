#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Count no. of ways
Rat in a maze - no of ways to reach the cheese by rat if he can move in 4 directions
                but cannot revisit a cell in the same path to avoid infinite loop
*/
int delr[4]={-1,0,0,1};
int delc[4]={0,-1,1,0};
    int recur(int i,int j,int n,vector<vector<int>>&maze,vector<vector<int>>&vis){
        if(i>=n || j>=n || i<0 || j<0)return 0;
        if(i==n-1 && j==n-1)return 1;
        int cnt=0;
        for(int k=0;k<4;k++){
            int row=i+delr[k];
            int col=j+delc[k];
            if(row<n && row>=0 && col<n && col>=0 && maze[row][col]==1 &&vis[row][col]==0){
                vis[row][col]=1;
                cnt+=recur(row,col,n,maze,vis);
                vis[row][col]=0;
            }
        }
        return cnt;
        
    }
int main(){
    vector<vector<int>>maze{{1,1,1},
                            {0,1,1},
                            {0,0,1}};
    int n=maze.size();
    vector<vector<int>>vis(n+1,vector<int>(n+1,0));
    vis[0][0]=1;
    cout<<recur(0,0,n,maze,vis);
    return 0;
}