#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
HW
https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14002?tab=statement
10. Regular Expression Matching - lc
*/

/*

44. Wildcard Matching
Pattern
ab*
Text
abca

-Match
*/


bool match(int i, int j,string&pattern, string&text,vector<vector<int>>&dp){
if(i<0 && j<0)return true;
if(i<0 && j>=0) return false;
if(j<0 && i>=0){
    for(int k=0;k<=i;k++){
        if(pattern[k]!='*')return false;
    }
    return true;
}
if(dp[i][j]!=-1)return dp[i][j];

    if(pattern[i]==text[j] || pattern[i]=='?'){
        return dp[i][j]=match(i-1,j-1,pattern,text,dp);
    }
    else if(pattern[i]=='*'){
        return dp[i][j]=(match(i-1,j,pattern,text,dp) || match(i,j-1,pattern,text,dp));
    }
    return dp[i][j]=false;
}

//Bottom up
bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
       vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
       dp[0][0]=true;
       for(int i=1;i<=n;i++){
           dp[i][0]=false;
       }
       for(int j=1;j<=m;j++){
           dp[0][j] = isAllStars(p, j);
       }

       for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(s[i-1]==p[j-1] or p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
             else if(p[j-1]=='*'){
                 dp[i][j]= dp[i-1][j] or dp[i][j-1];
             }
             else dp[i][j]=false;
         }
       }
       return dp[n][m];
    }
int main()
{ 
 string pattern;
 cin>>pattern;
 string text;
 cin>>text;
 int n=pattern.size();
 int m=text.size();
 vector<vector<int>>dp(n,vector<int>(m,-1));
 if(match(n-1,m-1,pattern,text,dp))cout<<"true"<<endl;
 else cout<<"false"<<endl;
 return 0;
}