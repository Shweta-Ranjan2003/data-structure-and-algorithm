#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
329 - Leetcode 
Given a 2-d matrix return a longest chain of numbers which are consecutive
in 8 directions
for eg
3 2 5
0 1 4
4 3 2
1 2 0
1 1 1

So the longest chain 1,2,3,4,5 starting from (4,1) to (0,2)
*/
//Recursive = N^2 8N^2
//Dp = N^2 
int delr[]={-1,-1,-1,0,0,1,1,1};
int delc[]={-1,0,1,-1,1,-1,0,1};

int recur(int i,int j,vector<vector<int>>&vec,vector<vector<int>>&dp){
    if(i>=vec.size() || j>=vec[0].size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int cnt=0;
    for(int k=0;k<8;k++){
        int row=i+delr[k];
        int col=j+delc[k];
        if(row>=0 && row<vec.size() && col>=0 && col<vec[i].size() &&
           vec[row][col]==(vec[i][j]+1)){
            cnt=max(cnt,1+recur(row,col,vec,dp));
           }
    }
    return dp[i][j]=cnt;
}
int main()
{ 
 vector<vector<int>>vec{{3,2,0,1},
                        {4,1,6,7},
                        {8,11,2,3},
                        {10,7,24,4},
                        {9,12,5,23},
                        {11,20,21,22}};
vector<vector<int>>dp(vec.size(),vector<int>(vec[0].size(),-1));
int ans=0;
  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++){
        ans=max(ans,1+recur(i,j,vec,dp));
    }
  }
  cout<<ans;
 return 0;
}