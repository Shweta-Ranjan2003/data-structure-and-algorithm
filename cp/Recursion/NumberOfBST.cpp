#include <iostream>
#include <vector>
using namespace std;
/*
Given N nodes return total no. of BST's that can be formed and no. of BT's that can be formed

Catalan Formula = 2n Cn / n+1
Read about catalan series and applications
*/

//BST
int ways(int n){
    if(n==0 || n==1)return 1;

    int ans=0;
    for(int i=1;i<=n;i++){
        int left_node=ways(i-1);  //IN left subtree of a root node we have options only for smaller value then i so we cann ways(i-1)
        int right_node=ways(n-i); //In right subtree we have options for greater value that are ways(n-i)
        ans+=(left_node*right_node);  //We are adding in ans because for every node we have to do OR because only one will be root
                                      //so we multiplying left and right but adding in ans to count all ways
    }
    return ans;
}
//Top down dp n^2
int waysDP(int n,vector<int>&dp){
if(n==0 || n==1)return 1;
if(dp[n]!=-1)return dp[n];
int ans=0;
for(int i=1;i<=n;i++){
    int left=waysDP(i-1,dp);
    int right=waysDP(n-i,dp);
    ans+=left*right;
}
return dp[n]=ans;
}
int waysBU(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            int left=dp[i-1];
            int right=dp[n-i];
            ans+=left*right;
        }
        dp[n]=ans;
    }
    return dp[n];
}


//BT - We will have to multiply N! to answer
int main()
{ 
 cout<<ways(3);
 return 0;
}