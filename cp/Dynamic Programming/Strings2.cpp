#include <iostream>
using namespace std;
/*
Distinct Subsequences
s1="babgbag" s2="bag"
how many times s2 is occuring in s1 (subsequence)

Trying out all ways and count ways

1.Express everything in terms of (i,j)
2.Explore all possibilites
3.return submission of all possibilites
4.Base case

f(i,j){
    if(j<0) return 1;
    if(i<0) return 0;
    if(s1[i]==s2[j]){
       return f(i-1,j-1) + f(i-1,j);
    }
    else return f(i-1,j);
}

//Memoization
dp[n][m];
i=n-1;
j=m-1;
f(i,j){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
       return dp[i][j]=f(i-1,j-1) + f(i-1,j);
    }
    else dp[i][j]=return f(i-1,j);
}

//Tabulation
Base case = shifting index i.e +1 with everything
vector<vector<double>>dp(n+1,vector<double>(m+1,0));
for(int i=0;i<=n;i++){ //when j=0 then no matter what i is we have to return 1;
    dp[i][0]=1;
}
for(int j=1;j<=m;j++){ //j=1 because we have to write dp[0][0] as 1 
    dp[0][j]=0;
}
 for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
    if(s1[i-1]==s2[j-1]){
       dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
    }
    else dp[i][j]=dp[i-1][j];
    }
 }
 return (int)dp[n][m];

 //Space optimization
 vector<double>prev(m+1,0);
 vector<double>curr(m+1,0);
 prev[0]=curr[0]=1; //base case
 for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
    if(s1[i-1]==s2[j-1]){
       curr[j]=prev[j-1] + prev[j];
    }
    else curr[j]=prev[j];
    }
    prev=curr;
 }
 return (int)prev[m];


 //While computing values in curr we dont have any use of curr row
 //1-D optimization
 vector<double>dp(m+1,0);
 dp[0]=1;
 for(int i=1;i<=n;i++){
    for(int j=m;j>=1;j--){
        if(s1[i-1]==s2[j-1]){
            dp[j]=dp[j-1]+dp[j];
        }
    }
 }
 return (int)dp[m];
*/

/*
Edit distance
s1="horse" s2="ros"
minimum operation to convert s1 to s2 using 1.insert 2.remove 3.replace
1.Express using index
2.Explore all paths of matching
3.Return min (all paths)
4.Base case

n-1,m-1
f(i,j){
//s1 get exhausted and s2 left then x insertion operation where x=no. of elements left in s2
//s1 is left but s2 exhausted then x deletion operation from 0th index to ith index in s1

if(i<0) return j+1;
if(j<0) return i+1;

if(s1[i]==s2[j]){
    return 0+f(i-1,j-1);
}
  min(1+f(i,j-1) ,//insert after inserting horses and ros i will remain at e and j will move to o
  1+f(i-1,j) ,//delete and move i-1 that is s and j at s
  1+f(i-1,j-1)); //replace
}

//Memoization
int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
        
    // Minimum of three choices
    else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
    min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));
    
}

//Tabulation
int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    
}

//Space optimization
int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        cur[0]=i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                cur[j] = 0+prev[j-1];
            
            else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
        }
        prev = cur;
    }
    
    return prev[m];
    
}
*/

/*
Wildcard Matching
? = matches with single character
* = matches with sequence of length 0 or more
s1="?ay"   s2="ray"  here ay matches with ay and ? corresponds to r which is single character so return true;
s1="ab*cd";  s2="abefgcd" here * matches to efg return true;
s1="ab?d" s2="abcc" return false as ? can only match with single character

f(i,j){
if(i<0 and j<0) return true;
if(i<0 and j>=0) return false;
if(j<0 and i>=0){
    for(k=0;k<=i;k++){
      if(s1[k]!='*') return false;
    }
    return true;
}
    if(s1[i]==s2[j] || s1[i]=='?'){
        return f(i-1,j-1);
    }
    if(s1[i]=='x'){
        return f(i-1,j) or f(i,j-1); //if star means nothing and if it does
    }
    return false;
}

//Memoization
vector < vector < bool >> dp(n, vector < bool > (m, -1));
f(i,j){
if(i<0 and j<0) return true;
if(i<0 and j>=0) return false;
if(j<0 and i>=0){
    for(k=0;k<=i;k++){
      if(s1[k]!='*') return false;
    }
    return true;
}
if (dp[i][j] != -1) return dp[i][j];

    if(s1[i]==s2[j] || s1[i]=='?'){
        return dp[i][j] = f(i-1,j-1);
    }
    if(s1[i]=='x'){
        return dp[i][j] =f(i-1,j) or f(i,j-1); //if star means nothing and if it does
    }
    return false;
}


//Tabulation
 int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    for(k=0;k<=i;k++){
      if(s1[k]!='*') {dp[i][0]=false; break;}
    }
    dp[i][j]=true;

  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (S1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];


//Space optimization
bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];
*/
int main()
{ 
 
 return 0;
}