#include <iostream>
using namespace std;

//Solve a problem in a pattern - partition dp
/*
Matrix chain multiplication
Given dimensions of n array return the minimum no. of operations required
to multiply those matrix

a = 10*30
b = 30*5
they can be multiplied because col of a is equal to row of b
size of new matrix will be = 10*5
operations = 10*30*5 = 1500
[1 2   [2
 3 1]   3]

 [1*2+2*3
  3*2+1*3]
  operations = 2*2*1 = 4

a=10*30   b=30*5  c=5*60
(ab)c =4500 operations
a(bc) =27000 operations

1. Start with entire block/array  f(i,j)
2. Try all partitions
ABCD - (A)(BCD)  (AB)(CD) (ABC)(D)
Run a loop to try all partitions
3. Return the best possible 2 partition

           i       j
arr[]=[10,20,30,40,50]
arr1=10*20
arr2=20*30 and so on
i=1 j=4

if k=i to j-1
then f(i,k),f(k+1,j)
else if we take k=i+1 to j
then f(i,k-1) , f(k,j)

f(i,j){
if(i==j) return 0;
mini=1e9;
for(int k=i;k<=j-1;k++){
    steps = arr[i-1]*arr[k]*arr[j] + f(i,k) + f(k+1,j); //dry run fo a example
    mini=min(mini,steps);
}
return mini;
}

//Memoization(Top down) bigger problem - smaller problem - base case
vector<vector<int>>dp(n,vector<int>(n,-1));
f(i,j,dp){
if(i==j) return 0;
if(dp[i][j]!=-1) return dp[i][j];
mini=1e9;
for(int k=i;k<=j-1;k++){
    steps = arr[i-1]*arr[k]*arr[j] + f(i,k) + f(k+1,j); //dry run fo a example
    mini=min(mini,steps);
}
return dp[i][j]=mini;
}

//Tabulation(bottom up) smaller problem - bigger problem
1. Copy the base case
dp[n][n];
for(int i=1;i<n;i++){
    dp[i][i]=0;
}
2.Write down changing parameters
i=n-1 to 0
j=i+1 to n-1  // i will always be one the left of j

3.Copy the recursion

dp[n][n];
for(int i=1;i<n;i++) dp[i][i]=0;
for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<n;j++){
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
            mini=min(mini,steps);
        }
        dp[i][j]=mini;
    }
}
return dp[1][n-1];
*/

/*
Minimum Cost to cut the stick
1,3,4,5  n=7 //7 is the initial length of stick
cost to cut a stick is the length of the stick you cut

0,1,2, 3, 5,7,8,12 
  i   cut     j 
cost to cut at 3 will be 12-0=12 which is the length of the stick

f(i,j){
    if(i>j) return 0;
    mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        cost = cuts[j+1]-cuts[i-1] + f(i,ind-1) + f(ind+1,j);
        mini=min(mini,cost);
    }
    return mini;
}
main(){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    return f(1,c,cuts);
}
//Memoization - dp[c+1][c+1];

//Tabulation
dp[c+2][c+2] = 0; //base case
i=c->1  //opposite of memoization
j=1->c  //opposite of memoization
for(int i=c;i>=1;i--){
    for(int j=1;j<=c;j++){
        if(i>j) continue;
        mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
        cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
        mini=min(mini,cost);
    }
    dp[i][j]=mini;
    }
}
return dp[1][c];
*/

/*
Burst Baloons
arr[] = [3,1,5,8]
you have to burst all baloon in any order and collect max coins 
each burst will give coins = arr[i-1]*arr[i]*arr[i+1]

max = 1,5,3,8 = 167
think it in opposite fashion to make the smaller problem independant because
if we think in straight manner then eg-
b1 b2 b3 b4 b5
if we burst b2 then smaller problem b1 will also be dependant on b3 and vice versa
so think in opposite fashion lets say for example
at end if b4 is left then for sure it would be in second last , it might be b1b4 b2b4 b3b4 b4b5 b4b6
and if second last is b2b4 then in third last for sure b2b4 will be there and so on

f(i,j){
    if(i>j) return 0;
    maxi=INT_MIN;
    for(ind i->j){
        cost=a[i-1]*a[ind]*a[j+1] + f(i,ind-1) + f(ind+1,j);
        maxi=min(maxi,cost);
    }
    return maxi;
}
int n=a.size();
a.push_back(1);
a.insert(a.begin(),1);
return f(1,n,a);  // i=1->n  and j=n->1;

//Memoization = dp[n+1][n+1]

//Tabulation
dp[n+2][n+2]=0;
for(int i=n;i>=1;i--){
    for(int j=1;j<=n;j++){
        if(i>j) continue;
       maxi=INT_MIN;
    for(int ind=i;ind<=j;ind++){
        cost=a[i-1]*a[ind]*a[j+1] + dp[i][ind-1] + dp[ind+1][j];
        maxi=min(maxi,cost);
    }
    dp[i][j]=maxi;
    }
}
return dp[1][n];
*/

/*
Evaluate Boolean Expression to True
T^F|T&F^T|F
Pattern = operands will always be at a distance of two indexes which means between two
count no. of ways to get a certain answer like true or false
so we can solve it like (T^F)|(T&F^T|F) to get true and there are many more ways to solve 
and get true count the ways

if left gives true in x ways and right gives true in y ways and there is a and between two
then no. of ways of getting true will be x*y

if there is or operator then getting true for left and right will be x1 x2
and false on left = x3 and false on right = x4
total ways of getting true = (x1*x2)+(x2*x3)+(x4*x1)

if there is xor operator then (x1*x4) + (x2*x3)

#define ll long long
const int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp, dp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp, dp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp, dp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}

*/

/* FRONT PARTITON LOGIC
Palindrome Partitioning -2 
return the minimum no. of partiton to make all the partition palindrome

aabb
a a b b = 3
aa bb = 1

f(i){
    if(i==n) return 0;
    mini=INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,str)){
            cost=1+f(j+1);
            mini=min(mini,cost);
        }
    }
    return mini;
}
int n=str.size();
return f(0,n,str)-1; //-1 because our code will make a partition right at the end also
//Memoization dp[n]=-1
//Tabulation
int n=str.size();
vector<int>dp(n+1,0);
dp[n]=0;
for(int i=n-1;i>=0;i--){
    int mini=INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,str)){
            int cost=1+dp[j+1];
            mini=min(mini,cost);
        }
    }
    dp[i]=mini;
}
return dp[0]-1;
*/

/*
Partition array for maximum sum
arr[1,15,7,9,2,5,10] k=3
at max length 3 is allowed
then maximize the sum if the entire subarray will change to maximum element of that partitoned subarray
[1,15 | 7,9,2 | 5,10]
[15,15| 9,9,9 | 10,10] = 77
[15,15,15|9|10,10,10] = 84

f(ind,k){
    int n=nums.size();
  if(ind==n) return 0;
  int len=0;
  int maxi=INT_MIN;
  int maxAns=INT_MIN;
  for(int j=ind;j<min(n,ind+k);j++){
    len++;
    maxi=max(maxi,num[j]);
    int sum=len*maxi + f(j+1);
    maxAns=max(maxAns,sum);
  }
  return maxAns;
}

//Memoization = dp[n]=-1;
//Tabulation  changing parameter means the ones that are passed in function
dp[n+1]=0;
for(int ind=n-1;ind>=0;ind--){
    int len=0;
  int maxi=INT_MIN;
  int maxAns=INT_MIN;
  for(int j=ind;j<min(n,ind+k);j++){
    len++;
    maxi=max(maxi,num[j]);
    int sum=len*maxi + dp[j+1];
    maxAns=max(maxAns,sum);
  }
  dp[ind]=maxAns;
}
return dp[0];
*/

/*
Maximum Rectangle Area with all 1's
largest rectangle in histogram - video pre req (not completed)

1 0 1 0 0   // 1 0 1 0 0
1 0 1 1 1   // 2 0 2 1 1
1 1 1 1 1   // 3 1 3 2 2
1 0 0 1 0   // 4 0 0 3 0

2*3 = 6 is max one

int largestarea(){
    stack<int>s;
    int maxA=0;
    int n=histo.size();
    for(int i=0;i<=n;i++){
        while(!st.empty() and (i==n||histo[st.top()]>=histo[i])){
            int height=histo[st.top()];
            st.pop();
            int width;
            if(st.empty()) {
                width=i;
            }
            else{
                width=i-st.top()-1;
            }
            maxA=max(maxA,width*height);
        }
        st.push(i);
    }
    return maxA;
}

int maxi=0;
vector<int>height(m,0);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]==1) height[j]++;
        else height[j]=0;
    }
    int area=largestarea(height);
    maxi=max(maxi,area);
}
return maxi;
*/

/*
Count square submatrices with all ones
1 0 1
1 1 0
1 1 0

6 square of 1 size
1 square of 2 size
= 7 square

tabulation
1 1 1
1 2 2
1 2 3
 
dp[i][j]= no. of square that can be formed with i,j being the right bottom
then total no. = sum of all dp[i][j]

1 1 1 1
1 1 1 1
1 1 1 1

1 1 1 1
1 2 2 2 //min of up and diagonal and left then +1
1 2 3 3

dp[n][m]=0;
for(int j=0;j<m;j++) dp[0][j]=arr[0][j];
for(int i=0;i<n;i++) dp[i][0]=arr[i][0];
for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(arr[i][j]==0)dp[i][j]=0;
        else{
            dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
}
int sum=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        sum+=dp[i][j];
    }
}
return sum;
*/
int main()
{ 
 
 return 0;
}