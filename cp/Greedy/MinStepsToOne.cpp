#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
1. Decrease a number by 1 = N-1
2. N=n/2
3. N=n/3

return min op to make n=1;
Greedy fails for N=10
greedy - 10 5 4 2 1
dp - 10 9 3 1
*/
int ways(int n,vector<int>&dp){
    if(n==1)return 0;
    if(dp[n]!=-1)return dp[n];

    int one=1+ways(n-1,dp);

    int two=INT_MAX;
    if(n%2==0) two=1+ways(n/2,dp);

    int three=INT_MAX;
    if(n%3==0) three=1+ways(n/3,dp);

    return dp[n]=min(one,min(two,three));
}
int main()
{ 
    int n;
    cin>>n;
 vector<int>dp(n+1,-1);
 cout<<ways(n,dp);
 cout<<endl;

 //Bottom up
 vector<int>dp2(n+1,INT_MAX);
 dp2[0]=0;
 dp2[1]=0;
 for(int i=2;i<=n;i++){

  int one=1+dp2[i-1];

  int two=INT_MAX;
  if(i%2==0) two=1+dp2[i/2];

  int three=INT_MAX;
  if(i%3==0) three=1+dp2[i/3];

  dp2[i]=min(one,min(two,three));
 }
 if(dp2[n]!=INT_MAX) cout<<dp2[n];
 else cout<<"NOT POSSIBLE";
 return 0;
}