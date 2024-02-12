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

/*
Cherry pickup
Fixed starting point ,variable ending points
Return max chocholates bob and alice can together collect.
We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, 
mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. 
initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). 
Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), 
to the bottom-right cell(↘), or to the bottom-left cell(↙).
Step 1: Express the problem in terms of indexes.
If we observe, initially Alice and Bob are at the first row, and they always move to the row 
below them every time, so they will always be in the same row. 
Step 2: Try out all possible choices at a given index.
Step 3:  Take the maximum of all choices

2 3 1 2
3 4 2 2
5 6 3 5

f(i,j1,j2){
if(j1<0 or j1>=m or j2<0 or j2>=m) return -1e9
if(i==n-1){
    if(j1==j2) return mat[i][j1]; //because bob and alice are on same cell
    else return mat[i][j1]+mat[i][j2];
}

maxi=INT_MIN;
for(int di=-1;di<=1;d++){
    for(int dj=-1;dj<=1;dj++){ //For every one movement of alice , bob can have 3 different movements like
                               // if alice(0,1) moves to a[1][0] bob(0,2) can move to a[1][1],a[1][2],a[1][3]
        if(j1==j2){
            ans=mat[i][j1] + f(i,j1+di,j2+dj);
        }
        else{
            ans= mat[i][j1]+mat[i][j2]+f(i,j1+di,j2+dj);
            maxi=max(maxi,ans);
        }
    }
    return maxi;
}
}


//Memoization
vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector <int> (m, -1)));
int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}


//Tabulation
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  vector< vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) { //at n-1 row alice and bob can both be at any position of m-1 col
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}

//Space optimization
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int > 
  (m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);

          }
        }
        cur[j1][j2] = maxi;
      }
    }
    front = cur;
  }

  return front[0][m - 1];

}

*/
int main()
{ 
 
 return 0;
}