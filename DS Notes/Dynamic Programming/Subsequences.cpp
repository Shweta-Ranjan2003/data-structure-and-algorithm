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
    dp[i][0]=true;
}
dp[0][a[0]]=true; //at index 0 we can only satisfy target which is equal to a[0] or it is 0
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
int main()
{ 
 
 return 0;
}