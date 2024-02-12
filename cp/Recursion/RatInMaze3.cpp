#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Count no. of ways + print using dp
bottom up - dp[i][j]=dp[i-1][j]+dp[i][j-1]

Rat in a maze - no of ways to reach the cheese by rat if he can move in 4 directions
                but cannot revisit a cell in the same path to avoid infinite loop
*/
int delr[4]={1,0};
int delc[4]={0,1};
    int recur(int i,int j,int n,vector<vector<int>>&maze,string&ds,vector<string>&ans){
        if(i>=n || j>=n || i<0 || j<0)return 0;
        if(i==n-1 && j==n-1){
            ans.push_back(ds);
            return 1;}
        int cnt=0;
        for(int k=0;k<2;k++){
            int row=i+delr[k];
            int col=j+delc[k];
            if(row<n && row>=0 && col<n && col>=0 && maze[row][col]==1){
                if(delr[k]==0 and delc[k]==1)ds.push_back('R');
                else if(delr[k]==1 and delc[k]==0)ds.push_back('D');
                cnt+=recur(row,col,n,maze,ds,ans);
                ds.pop_back();
            }
        }
        return cnt;
        
    }
int main(){
    vector<vector<int>>maze{{1,1,1},
                            {0,1,1},
                            {0,0,1}};
    int n=maze.size();
    string ds="";
    vector<string>ans;
    cout<<recur(0,0,n,maze,ds,ans)<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}