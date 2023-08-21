#include <iostream>
using namespace std;
/*
Subsequence -> contigous or non-contigous but have to follow order
[1,3,2]-> [1,2] [3,2] but not [2,3]

1. Subset sum equals to target
2 3 1 1 , target=4
f(ind,target){
    if(target==0) return true;
    if(ind==0) return (a[0]==target);

    bool notTake=f(ind-1,target);
    bool take=false;
    if(target>=a[ind]) take=f(ind-1,target-a[ind]);

    return (take) or (notTake);
}

//Memoization
dp[1001][1001];
f(ind,target){
    if(target==0) return true;
    if(ind==0) return (a[0]==target); 
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake=f(ind-1,target);
    bool take=false;
    if(target>=a[ind]) take=f(ind-1,target-a[ind]);

    return dp[ind][target]=(take) or (notTake);
}
*/

//Tabulation => bottom up (base case first then bottom up code)
/*
dp[n][target+1];
for(int i=0;i<n;i++){
    dp[i][0]=true; //if target is 0 then any index will return true;
}
if(a[0]<=target)dp[0][a[0]]=true; //at index 0 we can only satisfy target which is equal to a[0] or it is 0
for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
    }

//Space optimization
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}
*/

/*
patition equal subset sum
2 3 3 3 4 5
2 3 5    3 3 4 
s1=s2
s1+s2= s(total sum);   If odd then not possible
s1=total/2
now check if we have a subset with sum or target of s1
if yes then obviously remaining will be s2
Same as previous question above subset sum equals target

solve
int main(){
int total=0;
for(int i=0;i<n;i++) total+=arr[i];
if(total%2) return false;
int target=total/2;
vector<bool> prev(k+1,false);
    
        prev[0] = true;
        
        if(arr[0]<=k)
            prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(k+1,false);
            cur[0] = true;
            for(int target= 1; target<=k; target++){
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
            prev = cur;
        }
        
        return prev[k];
}
*/


/*
Partition a set into two subsets such that the difference of subset sums
is minimum
[1,2,3,4] = [1,4][2,3] then difference is 0 which is minimum
If we tabulate the subset sum equals k then by using that tabulated table
we can easily find the s1(sum of subset 1) then subtract it from target 
and that will be the sum of s2(remaining elements subset) and find the
difference of subset -> we can check for half of the subset to optimize
because after half the subset would be just the swap of no. between two no.


int minSubset(vector<int>&arr , int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    int k=total;
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target]=take or notTake;
        }
    }

    int mini=1e9;
    for(ind s1=0;s1<=total/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs((total-s1)-s1));
        }
    }
    return mini;
}

//Space optimization
int minSubset(vector<int>&arr , int n){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    int k=total;
    vector < bool > prev(total + 1, false);

  prev[0] = true;

  if (arr[0] <= total)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    vector < bool > cur(total + 1, false);
    cur[0] = true;
    for (int target = 1; target <= total; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  int mini = 1e9;
  for (int i = 0; i <= total; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (total - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}
*/

/*
count no of subset with sum k
(In count question if we find we return 1 else 0 and at the end the sum of
both function is returned,if multiple function calls are there then sum of all)

 f(ind , s){
    if(s==0) return 1;
    if(ind==0){
       return (a[ind]==s);
    }
    notPick=f(ind-1,s);
    pick=0;
    if(a[ind]<=s) pick=f(ind-1,s-a[ind]);

    return pick+notPick;
 }

 //Memoization
 dp[n][sum+1];
 f(ind , s){
    if(s==0) return 1;
    if(ind==0){
       return (a[ind]==s);
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    notPick=f(ind-1,s);
    pick=0;
    if(a[ind]<=s) pick=f(ind-1,s-a[ind]);

    return dp[ind][sum]=pick+notPick;
 }
 //If test case are designed to have 0 as well like {0,0,1} then
 change the base case as
 f(ind , s){
    if(ind==0){
       if(sum==0 && num[0]==0) return 2;
       if(sum==0 || sum==num[0]) return 1;
       return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    notPick=f(ind-1,s);
    pick=0;
    if(a[ind]<=s) pick=f(ind-1,s-a[ind]);

    return dp[ind][sum]=pick+notPick;
 }

 //Tabulation
 1. Base case
 2. Look at the changing parameters and write nested loops
 3. copy the recursion

 int dp[n][s+1];
 for(int i=0;i<n;i++){
    dp[i][0]=1;
 }
 if(num[0]<=s)dp[0][num[0]]=1;
for(int i=1;i<n;i++){
    for(int sum=1;sum<=target;sum++){
      int notTake=dp[ind-1][sum];
      int take=0;
      if(num[ind]<=sum) take=dp[ind-1][sum-num[ind]];  
      
      dp[ind][sum]=take+notTake;
    }
}
return dp[ind-1][target];

//Space optimization
int n=nums.size();
vector<int> prev(target+1,0), curr(target+1);
prev[0]=curr[0]=1;
if(nums[0]<=target) prev[nums[0]]=1;
for(int ind=1;ind<n;ind++){
    for(int sum=0;sum<=target;sum++){
        int notTake=prev[sum];
        int take=0;
        if(nums[ind]<=sum) take=prev[sum-nums[ind]];

        curr[sum]=take+notTake;
    }
    prev=curr;
}
return prev[target];
}
*/

/*
Partition with given difference
partition an array into s1 and s2 such that s1 is greater then s2 and difference
between s1 and s2 is equal to D.
(s1-s2=d)  s1>=s2
s1=total-s2
total-s2-s2=d
total-d=2*s2
s2=total-d / 2

count of subsets whose sum is total-d/2
edge cases -> total-d>=0 and total-d should be even

int count(ind n,ind d, vector<int>&arr){
    int total=0;
    for(auto &it: arr) total+=it;
    if(total-d<0 || (total-d)%2) return false;
     vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr,dp);
}

//Memoization
int mod=(int)(1e9+7);
f(ind , s){
    if(ind==0){
       if(sum==0 && num[0]==0) return 2;
       if(sum==0 || sum==num[0]) return 1;
       return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    notPick=f(ind-1,s);
    pick=0;
    if(a[ind]<=s) pick=f(ind-1,s-a[ind]);

    return dp[ind][sum]=(pick+notPick)%mod;
 }



//Tabulation

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

//Space optimization
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}
*/
int main()
{ 
 
 return 0;
}