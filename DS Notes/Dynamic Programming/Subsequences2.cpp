#include <iostream>
using namespace std;

/*
Longest Increasing Subsequence
arr[]= [10,9,2,5,7,101,18]
o/p - len 4 - [2,3,7,101]
Subsequence -> contigous or non-contigous but have to follow order

Trying all ways
1. Express everything in terms of indexes
2. Explore all
3. Take the max length (not take , take)
4. base case
f(ind , prevInd){
    if(ind==n) return 0;
    len = 0+f(ind+1,prevInd) //not take
    if(prevInd==-1 or arr[ind]>arr[prevInd]){
       len = max(len, 1+f(ind+1,ind)) //take
    }
    return len;
}

//Memoization
coordinate shift because storing prevInd =-1 is not possible
dp[n][n+1];
f(ind , prevInd){
    if(ind==n) return 0;
    if(dp[ind][prevInd+1]!=-1) return dp[ind][prev-ind+1];
    len = 0+f(ind+1,prevInd) //not take
    if(prevInd==-1 or arr[ind]>arr[prevInd]){
       len = max(len, 1+f(ind+1,ind)) //take
    }
    return dp[ind][prevInd+1]=len;
}

//Tabulation
1. Base case
dp[n+1][n+1]=0
2. ind = n-1->0
   prevInd=ind-1->-1

3.Copy the recurrence

for(int ind=n-1;ind>=0;ind--){
    for(int prev=ind-1;prev>=-1;prev--){ //previous index is a previous index of index so it should start from index 
        int len=0+dp[ind+1][prev+1];
        if(prev==-1 or arr[ind]>arr[prev]){
            len=max(len , 1+dp[ind+1][ind+1]);
        }
        dp[ind][prev+1]=len;
    }
}
return dp[0][-1+1];

//Space optimization
next[n+1] , curr[n+1];
for(int ind=n-1;ind>=0;ind--){
    for(int prev=ind-1;prev>=0;prev--){
        int len=0+next[prev+1];
        if(prev==-1 or arr[ind]>arr[prev]){
            len=max(len , next[ind+1]); //at ind+1 make is next and at ind make is curr
        }
        next=curr;
    }
}
return next[-1+1];


//Intitution O(n^2) required to print the lis
// 5 4 11 1 16 8
vector<int>dp(n,1); //The min length at all index will be 1
for(int i=0;i<n;i++){
    for(int prev=0;prev<i;prev++){
        if(arr[prev]<arr[i]){
            dp[i]=max(dp[i],1+dp[prev]);
        }
    }
    maxi=max(maxi,dp[i]);
}
return maxi;

//Print LIS  (backtracking)
5  4  11  1  16  8
1  1  2   1  3  2  dp
0  1  0   3   2  0  hash

max at ind 3 then at 
start with 4 store 16 then at 2 store  11 then at 0 store 5  then reverse it 

vector<int>dp(n,1),hash(n);  //every element will be atleast 1
int maxi=1;
int last=0;
for(int i=0;i<n;i++){
    hash[i]=i;
    for(int prev=0;prev<i;prev++){
        if(arr[prev]<arr[i]&&1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
            hash[i]=prev;
        }
    }
    if(dp[i]>maxi){
        maxi=dp[i];
        last=i;
    }
}
vector<int>temp;
temp.push_back(arr[last]);
while(hash[last]!=last){
    last=hash[last];
    temp.push_back(arr[last]);
}
reverse(temp.begin(),temp.end());
for(auto it:temp) cout<<it<<" ";
cout<<endl;
return maxi;
*/
/*
LIS using Binary Search
1 7 8 4 5 6 -1 9
1 7 8 9
1 4 5 6 9 // because 4 can not go with 1 7 8 then we start it as a fresh subsequence
-1 9

we will create a replicate by inserting element at their place
by binary search
1  7  8
1  4  8 //replacing 7 with 4 and continuing it because whatever will be greated then 7 will obvioulsy be greater then 4
1  4  5
1  4  5  6
-1 4  5  6
-1 4  5  6  9

vector<int>temp;
temp.push_back(arr[0]);
int len=1;
for(int i=1;i<n;i++){
    if(arr[i]>temp.back()){
        temp.push_back(arr[i]);
        len++;
    }
    else{
        int ind=lower_bound(temp.begin(),temp.end(),arr[i]);
        temp[ind]=arr[i]
    }
}
return len;
*/
/*
Largest Divisible Subset
1  16  7  8  4
1  16  8  4
 
if 8 is divisble by 4 and 4 is divisible by 1 then 8 is also divisible by 1
same as lis
int n=arr.size();
vector<int>dp(n,1),hash(n);  //every element will be atleast 1
int maxi=1;
int last=0;
sort(arr.begin(),arr.end());
for(int i=0;i<n;i++){
    hash[i]=i;
    for(int prev=0;prev<i;prev++){
        if(arr[i]%arr[prev]==0 &&1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
            hash[i]=prev;
        }
    }
    if(dp[i]>maxi){
        maxi=dp[i];
        last=i;
    }
}
vector<int>temp;
temp.push_back(arr[last]);
while(hash[last]!=last){
    last=hash[last];
    temp.push_back(arr[last]);
}
reverse(temp.begin(),temp.end());
return temp;

*/
/*
Longest string chain
words[] = {'a','b','ba','bca','bda','bdca'}
wordA is a predecessor of wordB if and only if we can insert exactly 
one letter anywhere in wordA without changing the order of the other 
characters to make it equal to wordB.
Return the length of the longest possible word chain with words 
chosen from the given list of words.

same as LIS just a little change
bool check(string &s1,string &s2){
    if(s1.size()!=s2.size()+1) return false;
    int first=0;
    int second=0;
    while(first<s1.size()){
        if(second<s2.size() and s1[first]==s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first==s1.size() and second==s2.size()) return true;
    return false;
}
bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}
sort(arr.begin(),arr.end(),comp);  //sorting according to length
vector<int>dp(n,1); 
int maxi=1;
for(int i=0;i<n;i++){
    for(int prev=0;prev<i;prev++){
        if(check(arr[i],arr[prev]) and 1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
        }
    }
    if(dp[i]>maxi){
        maxi=dp[i];
    }
}
return maxi;
*/
/*
Longest Bitonic Subsequence
bitonic - increase and decrease or just increase or decrease
arr[]= 1  11  2  10  4  5  2  1
dp1[]= 1  2  2   3   3  4  2  1 //increasing
dp2[]= 1  5  2   4   3  3  2  1 //decreasing or eye from right side in LIS
bitonic can be count by including both dp1 and dp2 so we will have all combination of increasing decreasing
bit[]= 1  6  3   6   5  6  3  1  //why -1 because lets say for 10 3 for increasing and 4 for decreasing but 10th is count twice so -1

  vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i]){
                dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
            }
        }
    }
    
    // reverse the direction of nested loops
    for(int i=n-1; i>=0; i--){
        for(int prev_index = n-1; prev_index >i; prev_index --){
            
            if(arr[prev_index]<arr[i]){
                dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
            }
        }
    }
    
    int maxi = -1;
    
    for(int i=0; i<n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    
    return maxi;
*/

/*
Number of longest increasing subsequence
arr[] = 1 , 5 , 4 , 3 , 2 , 6 , 7 , 10 , 8 , 9
dp[] =  1 , 2 , 2 , 2 , 2 , 3 , 4 , 5 , 5 , 5
cnt[] = 1 , 1 , 1 , 1 , 1 , 4 , 4 , 4 , 4 , 4

vector<int>dp(n,1) , cnt(n,1);
int maxi=1;
for(int i=0;i<n;i++){
    for(int prev=0;prev<i;prev++){
        if(arr[prev]<arr[i] and 1+dp[prev]>dp[i]){
            dp[i]=1+dp[prev];
            // inherit
            cnt[i]=cnt[prev];
        }
        else if(arr[prev]<arr[i] and 1+dp[prev]==dp[i]){
            //increase the cnt
            cnt[i]+=cnt[prev];
        }
    }
    maxi=max(maxi,dp[i]);
}
int nos=0;
for(int i=0;i<n;i++){
    if(dp[i]==maxi) nos+=cnt[i];
}
return nos;
*/
int main()
{ 
 
 return 0;
}