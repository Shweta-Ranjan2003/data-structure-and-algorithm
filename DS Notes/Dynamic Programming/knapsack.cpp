#include <iostream>
using namespace std;
/*
0/1 Knapsack problem
1. Express everything in terms of (ind,W) W=weight
2. Explore all possibilities 
3. Max of all possibility

3  2  4
30 40 60

f(ind,w){
if(ind==0){
    if(wt[0]<=w) return val[0];
    return 0;
}

notTake=0+f(ind-1,w);
take=INT_MIN;
if(wt[ind]<=w) take=val[ind]+f(ind-1,w-wt[ind]);

return max(take,notTake);
}

//Memoization
dp[n][w+1];
f(ind,w){
if(ind==0){
    if(wt[0]<=w) return val[0];
    return 0;
}
if(dp[ind][w]!=-1) return dp[ind][w];
notTake=0+f(ind-1,w);
take=INT_MIN;
if(wt[ind]<=w) take=val[ind]+f(ind-1,w-wt[ind]);

return dp[ind][w]=max(take,notTake);
}


//Tabulation
1.Base case 
2. Changing parameter-> nested loops
3. copy the recursion

vector<vector<int>> dp(n,vector<int> (maxweight+1,0));
for(int w=wt[0];w<=maxweight;w++){
    dp[0][w]=val[0];
}
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

//Space optimization
vector<int> prev(maxweight+1,0) , curr(maxweight+1,0);
for(int w=wt[0];w<=maxweight;w++){
   prev[w]=val[0];
}
for(int ind=1;ind<n;ind++){
    for(ind w=0;w<=maxweight;w++){
        int notTake=0+prev[w];
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+prev[w-wt[ind]];
        }
        curr[w]=max(take,notTake);
    }
    prev=curr;
}
return prev[maxweight];

//Further space optimization
vector<int> prev(maxweight+1,0);
for(int w=wt[0];w<=maxweight;w++){
   prev[w]=val[0];
}
for(int ind=1;ind<n;ind++){
    for(ind w=maxweight;w>=0;w--){ //Moving right to left instead of left to right
        int notTake=0+prev[w];
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+prev[w-wt[ind]];
        }
        prev[w]=max(take,notTake);
    }
}
return prev[maxweight];
*/


/*
Minimum coins
minimum no. of coin required to reach target amount
{9,6,5,1}  target=11
{9,1,1}=3
{6,5}=2
 
 //Memoization
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

//Tabulation
for(int t=0;t<target;t++){
    if(t%a[0]==0){
        dp[0][t]=t/a[0];
    }
    else dp[0][t]=1e9;
}
 
 for(int ind=1;ind<n;ind++){
    for(int t=0;t<=target;t++){
        int notTake=0+dp[ind-1][t]; //dp[ind-1] is prev
        int take=1e9;
        if(nums[ind]<=t){
            take=1+dp[ind][t-nums[ind]]; //dp[ind] is curr
        }
        dp[ind][t]=min(take,notTake);
    }
 }
 return dp[n-1][target];

 //Space optimization
 int n=nums.size();
 vector<int> prev(target+1,0), curr(target+1,0);
 for(int t=0;t<=target;t++){
    if(t%nums[0]==0) prev[t]=t/nums[0];
    else prev[t]=1e9;
 }
 for(int ind=1;ind<n;ind++){
    for(int t=0;t<=target;t++){
         int notTake=0+prev[t];
        int take=1e9;
        if(nums[ind]<=t){
            take=1+curr[t-nums[ind]];
        }
        curr[t]=min(take,notTake);
    }
    prev=curr;
 }
 return prev[target];
*/
int main()
{ 
 
 return 0;
}