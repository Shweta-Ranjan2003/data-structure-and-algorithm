#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
1.
{1,2,5,10,20,50,100,200,500}
min notes to make amt=458
*/

//Greedy fails for some test cases 
int notes(int amt,vector<int>&note){
    int cnt=0;
    while(amt){
        int it=lower_bound(note.begin(),note.end(),amt)-note.begin();
         cnt+=(amt/note[it]);
         amt=amt-((amt/note[it])*note[it]);
    }
    return cnt;
}

//Recursion + Dp
int recur(int ind,int amount,vector<int>&coins,vector<vector<int>>& dp){
    if(ind==0){
        if(amount%coins[ind]==0){
             return amount/coins[ind];
        }
        return 1e9;
    }
   if(dp[ind][amount]!=-1) return dp[ind][amount];
    //pick
    int take=INT_MAX;
    if(amount-coins[ind]>=0){
      take=1+ recur(ind,amount-coins[ind],coins,dp);
    }

    //not pick
    int notTake=0;
    notTake=recur(ind-1,amount,coins,dp);

    return dp[ind][amount]=min(take,notTake);
}
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int count=recur(n-1,amount,coins,dp);
        if(count!=1e9)return count;
        return -1;
}
int main()
{ 
 //vector<int>note{1,2,5,10,20,50,100,200,500};
 //cout<<notes(458,note);
 //cout<<coinChange(note,458);

vector<int>coins{1,7,10};
int n=coins.size();
int amt=15;
vector<int>dp(amt+1,INT_MAX);
dp[0]=0;
for(int i=1;i<=amt;i++){
    int mini=INT_MAX;
    for(int j=0;j<n;j++){
        if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
          mini=min(mini,1+dp[i-coins[j]]);
        }
    }
    dp[i]=mini;
}
if(dp[amt]==INT_MAX) cout<<"Not Possible";
else cout<<dp[amt];
 return 0;
}