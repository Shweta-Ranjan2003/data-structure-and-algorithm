#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
0-1 Knapsack
*/

int recur(int i,vector<int>&w,vector<int>&p,int weight, vector<vector<int>>&dp){
    if(i<0 || weight==0){
        return 0;
    }
    if(dp[i][weight]!=-1)return dp[i][weight];
    //pick
    int pick=INT_MIN;
    if(w[i]<=weight) pick=p[i]+recur(i-1,w,p,weight-w[i],dp);
    //not pick
    int not_pick=recur(i-1,w,p,weight,dp);
    return dp[i][weight]=max(pick,not_pick);
}

//Not understood
int BU(vector<int>&wt,vector<int>&p,int maxweight){
    int n=w.size();
    vector<vector<int>>dp(n+1,vector<int>(weight(maxweight+1,0)));
    for(int ind=1;ind<n;ind++){
    for(ind w=0;w<=maxweight;w++){
        int notTake=0+dp[ind-1][w];
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+dp[ind-1][w-wt[ind]];
        }
        dp[ind][w]=max(take,notTake);
    }
}
return dp[n-1][maxweight];
}

//Hw - print items which you have picked
int main()
{ 
 vector<int>w{1,5,3,7};
 vector<int>p{20,30,15,40};
 int n=w.size();
 int weight=10;
 vector<vector<int>>dp(n+1,vector<int>(weight+1,-1));
 cout<<recur(n-1,w,p,weight,dp);
 return 0;
}