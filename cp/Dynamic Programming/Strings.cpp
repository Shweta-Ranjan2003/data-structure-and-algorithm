/*
A subarray is a contiguous part of array and maintains relative ordering of elements. For an array/string of size n, there are n*(n+1)/2 non-empty subarrays/substrings.

A subsequence maintain relative ordering of elements but may or may not be a contiguous part of an array. For a sequence of size n, we can have 2^n-1 non-empty sub-sequences in total.

A subset MAY NOT maintain relative ordering of elements and can or cannot be a contiguous part of an array. For a set of size n, we can have (2^n) sub-sets in total.
when we find subset of a set we dont take a subset which is a premutation
A substring is exactly the same thing as a subarray but in the context of strings.
*/
#include <iostream>
using namespace std;
/*
Longest common subsequence
find the longest common subsequence among all the subsequences of both the string
1. Express in index1,index2
2. Explore possibility on that index
3. Take the best among them

a=acd  b=ced
so starting from back d and d matches so it will surely be present in lcs
at index1=1 and index2=1 , c and e doesnt match so we have to then go in both path
that is moving index1 one index back and keeping index2 at that place only
or vice versa then take max of both lcs

match on index
1+f(ind1-1,ind2-1);
not match
0+max(f(ind1-1,ind2),f(ind1,ind2-1));

f(ind1,ind2){
    if(ind1<0||ind2<0) return 0;
    if(s1[ind1]==s2[ind2]){
        return 1+f(ind1-1,ind2-1);
    }
    return max(f(ind1-1,ind2),f(ind1,ind2-1));
}

//Memoization
dp[n][m]->-1
f(ind1,ind2){
    if(ind1<0||ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]){
        return dp[ind1][ind2]= 1+f(ind1-1,ind2-1);
    }
    return dp[ind1][ind2]=max(f(ind1-1,ind2),f(ind1,ind2-1));
}

//Tabulation
1. copy the base case
2. loop for ind1 and ind2 
for base case of negative index we will do shifting of index
we will consider every index as i-1 like n means index n-1 , 1 means index 0
so base case will be if ind1==0 or ind2==0 then return 0
which means some negative index
3. copy the recursion
dp[n+1][m+1]
int n=s1.size();
int m=s2.size();
for(ind1=0;ind1<=n;ind1++){
    dp[ind1][0]=0;
}
for(ind2=0;ind2<=m;ind2++){
    dp[0][ind2]=0;
}
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
            }
            else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    }
    return dp[n][m];
}


//Space optimization
int n=s1.size();
int m=s2.size();
vector<int>prev(n+1,0),curr(m+1,0);
for(int i=0;i<=n;i++) prev[i]=0;

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
        else curr[j]=max(prev[j],curr[j-1]);
    }
    prev=curr;
}
return prev[m];
*/

/*
Printing LCS
s1="abcde" s2="bdgek"
dp 26 video 
first tabulate the lcs

string ans="";
len=dp[n][m];  //length of lcs
for(i=0;i<len;i++){
 ans+='$';
}
index=len-1;
i=n,j=m;
while(i>0 and j>0){ //because 0th row and 0th col was whole 0
    if(s1[i-1]==s2[j-1]){
      ans[index]=s1[i-1];
      index--;
      i--;
      j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
       i=i-1;
    }
    else{
        j=j-1;
    }
}
return ans;
*/

/*
Longest common substring (consecutive)
//Tabulation
int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                ans = max(ans,val);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
//Printing LCSubstring

//         d  a  b  a  b
//      0  1  2  3  4  5
//   0  0  0  0  0  0  0
// b 1  0  0  0  1  0  1
// a 2  0  0  1  0  2  0
// b 3  0  0  0  2  0  3
// a 4  0  0  1  0  3  0
// d 5  0  1  0  0  0  0


sstring str="";

int len=dp[maxiI][maxiJ];  //here maxi will not be necessarily stored at last index so we have to keep track of maxiI=3 and maxiJ=5
for(int i=0;i<len;i++){
 str+='$';
}
int index=len-1;
while(maxiI>0 and maxiJ>0){ //because 0th row and 0th col was whole 0
    if(s1[maxiI-1]==s2[maxiJ-1]){
      str[index]=s1[maxiI-1];
      index--;
      maxiI--;
      maxiJ--;
    }
    else{
        break;
    }
}
return str;


//Space optimization
 int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1,0), cur(m+1,0);

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0;
        }
        prev=cur;
    }
    
    return ans;
*/

/*
Longest Palindromic subsequence
s1="bbabcbcab"
s2="bacbcbabb" //reverse the s1 and now the lcs of both will be longest palindrome subsequence

    
    int n=s1.size();
    int m=n;
    string s2=s1.reverse();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];


//Space optimization
   int n=s1.size();
    int m=n;
    string s2=s1.reverse();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return prev[m];
}

*/

/*
Minimum insertion to make string palindrome
in codingninjas   ingni is already longest palindromic subsequence
to make it palindrome we have to copy the letters before ingni that are cod at end in opposite manner
and njas after cod  in opposite manner
cod sajn ingni njas doc

basically we have to find the longest palindromic subsequence(lps) and then
n-lps is the total insertion we have to make in order to make it a palindrome

int n=s1.size();
    int m=n;
    string s2=s1.reverse();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return n-prev[m];
}
*/

/*
Minimum operation to convert string 1 to string 2
str1="abcd"  str2="anc"
delete b and d and insert n = 3 operation
n=str1.size()
m=str2.size()
deletion = n-len(lcs)
insertin=m-len(lcs)
answer=(n+m)-2*len(lcs)
*/

/*
Shortest common supersequence
s1="brute"
s2="groot"
"brutegroot"=supersequence
shortest supersequence = "bgruoote"  (A sequence which has both)
len=8

common elements will be only once in supersequence (lcs)
so length will be n+m-len(lcs);

string?
print lcs
        g  r  o  o  t
     0  1  2  3  4  5
  0  0  0  0  0  0  0
b 1  0  0  0  0  0  0
r 2  0  0  1  1  1  1
u 3  0  0  1  1  1  1
t 4  0  0  1  1  1  2
e 5  0  0  1  1  1  2

at[5][5] e and t doesnt match so take move it to [4][5] and write e to you string
then ar [4][5] t matches t so just write t in string and move to [3][4]
at [3][4] u doesnt match o so either move [2][4] and write u to string
or write o to string and move to [3][3] and so on
string = etouorbg  and then reverse it because we started from back

i=n,j=m
while(i>0 and j>0){
    if(s1[i-1]==s2[j-1]){
        ans+=s1[i-1];
        i--;
        j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]{
       ans+=s1[i-1];
       i--;
    }
    else{
        ans+=s2[j-1];
        j--;
    }
}
if(something of i is remaining but j==0 and exited the while loop then write ith elements at end and vice versa)
while(i>0) {
    ans+=s1[i-1];
    i--;
    }
while(j>0){
    ans+=s2[j-1];
    j--;
}

reverse(ans);
return ans;
*/
int main()
{ 
 
 return 0;
}