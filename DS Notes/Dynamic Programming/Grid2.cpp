#include <iostream>
using namespace std;
/*
Minimum/Maximum Falling path sum
n*m matrix , find the max sum that can be obtained from a path starting from any
cell in the first row to any cell in last row -> move directly down or diagonal to left or right
 1. Express everything in terms of index
 2. explore all path
 3. max among all paths
f(i,j){
    if(j<0 or j>m) return -1e8;
    if(i==0) return a[0][j];
    int up=     a[i][j]+f(i-1,j);
    int leftd=  a[i][j]+f(i-1,j-1);
    int rightd= a[i][j]+f(i-1,j+1);
    
    return max(up,leftd,rightd);

}
int main()
int maxi=-1e8
for(int j=0;j<n;j++){
    maxi=max(maxi,f(m-1,j,matrix));
}
return maxi;


//Memoization
vector<vector<int>>dp(m,vector<int>(n,-1));
f(i,j,dp){
    if(j<0 or j>m) return -1e9;
    if(i==0) return a[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int up=     a[i][j]+f(i-1,j,dp);
    int leftd=  a[i][j]+f(i-1,j-1,dp);
    int rightd= a[i][j]+f(i-1,j+1,dp);
    
    return dp[i][j]=max(up,leftd,rightd);

}
int main()
int maxi=-1e8
for(int j=0;j<n;j++){
    maxi=max(maxi,f(m-1,j,matrix));
}
return maxi;

//Tabulation
int dp[m][n];
for(int j=0;j<n;j++){
    dp[0][j]=a[0][j];
}
for(int i=1;i<m;i++){
    for(int j=0;j<n;j++){
        int up=a[i][j]+dp[i-1][j];
        int ld=a[i][j];
       if(j-1>=0) ld+=dp[i-1][j-1];
       else ld+=-1e8
       int rd=a[i][j];
       if(j+1<m) rd+=dp[i-1][j+1];
        dp[i][j]=max(up,ld,rd);
    }
} 
int maxi=dp[n-1][0];
for(int j=1;j<m;j++){
    maxi=max(maxi,dp[n-1][j]);
}
return maxi;

//Space optimization
prev[n,0],curr[n,0];
for(int j=0;j<n;j++){
    prev[j]=a[0][j];
}
for(int i=1;i<m;i++){
    for(int j=0;j<n;j++){
        int up=a[i][j]+prev[j];
        int ld=a[i][j];
       if(j-1>=0) ld+=prev[j-1];
       else ld+=-1e8;
       int rd=a[i][j];
       if(j+1<m) rd+=prev[j+1];
       else rd+=-1e8;
        curr[j]=max(up,ld,rd);
    }
    prev=curr;
} 
int maxi=prev[0];
for(int j=1;j<m;j++){
    maxi=max(maxi,prev[j]);
}
return maxi;
*/
int main()
{ 
 
 return 0;
}