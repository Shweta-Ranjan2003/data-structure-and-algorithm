/*
1. Try to represent the problem in terms of index
2. Do all possible stuffs on that index according to the problem statement
3. Sum of all stuffs -> count all ways
   min of all stuffs -> find min
*/
#include <iostream>
using namespace std;
/*
Those who cannot remember the past are condemned to repeat it

Dynamic programming is used so that we do not have to resolve a similar problem again and again 
we can simply store the answer and use that answer whenever needed instead of repeatedly calculating it everytime.
Where it is used:-
1. Overlapping subproblems - eg.fibonacci number - f(5)=f(4)+f(3)
                                                   f(4)=f(3)+f(2) , f(3)=f(2)+f(1)
                                                   f(3)=f(2)+f(1) . Here we can see that we are finding 
                                                   f(4) and f(3) more than once so it is overlapping subproblem
2. Maximize/Minimize some value
3. Finding number of ways
4. Covering all cases (DP vs Greedy) - Greedy goes in a certain direction but dp covers all possible direction and then give answer
5. Check for possibility
*/

/*
Ways to solve dp:-
1. Memoization (top down) -> Tend to store the value of subproblems in some map/table
and use it whenever needed in further question so that we do not have to solve the same subproblem again
// Overlapping Subproblem
f(n){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=f(n-1)+f(n-2);
}
// TC - O(N) SC- O(N)+O(N) // recursion stack space + array space
step 1:- make a array and initilize it to some value which will never be the answer of any subproblem eg -1 for fibonacci sequence
step 2:- check if the nth no. is already calculated and stored in array or not if yes then instead of solving it again use the value
step 3:- store the new value which is calculated in dp array for further use

2. Tabulation (Bottom up)
Start from the base case and get to required answer
dp[0]=0; dp[1]=1;
for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];
//TC - O(n) SC- O(n)

****Optimized solution****
int prev=1;
int prev2=0;
for(int i=2;i<=n;i++){
    int curr=prev+prev2;
    prev2=prev;
    prev=curr;
}
return prev;
*/
/*
MEMOIZATION - TOP-DOWN
we calculate f(x) once and store it somewhere and use it whenever needed in future
eg:-
int count=0;
int helper(int n){
    count++;
    if(n==1||n==2){
        return 1;
    }
    return helper(n-1)+helper(n-2);
}
Here for n=30 , count=1664079

//memoization
int count=0;
int dp[31]; (initialize it to -1 for all index)
int helper(int n){
    count++;
    if(n==1||n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=helper(n-1)+helper(n-2);
}
Here for n=30 , count=57
*/

/*
Climbing stairs -> one or two stairs at a time , return total no. of ways to climb nth stair
f(ind){
    if(ind==0) return 1;
    if(ind==1) return 1;
    left=f(ind-1);
    right=f(ind-2);
    return left+right;
}

//******Optimize solution*****
if(n==1||n==2) return n;
        int prev=2;
        int prev2=1;
        for(int i=3;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
*/

//Maximize some value
/*
Q. Given an array of positive and negative values . Pick a subsequence of elements from it such that
no 2 adjacent elements are picked and the sum of picked elements is maximized.

1 , 4 , 2 , -10 , 10 , 5 -
sum 14(4,10) , sum 13(1,2,10)
*/

/*
House robber -> no two adjacent house should be robbed and maximize the amount if robbery
//Recursion 2^n
f(ind){
    if(ind==0) return a[ind];
    if(ind<0) return 0;
    pick=a[ind]+f(ind-2);
    notPick=0+f(ind-1);
    return max(pick,notPick);
}

//Memoization
int f(ind ind, vector<int> &nums , vector<int> &dp){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind]+f(ind-2,nums,dp);
    int notPick=0+f(ind-1,nums,dp);

    return dp[ind]=max(pick,notPick);
}

//Tabulation
 dp[0]=a[0];
 int neg=0;
 for(int i=1;i<n;i++){
    take= a[ind];
    if(i>1) take+=dp[i-2]; //take=a[ind]+dp[i-2];
    notTake=0+dp[i-1]; //notTake=0+dp[i-1];
    dp[i]=max(take,notTake);
 }


//*****Space optimization****
We only need dp[i-1] and dp[i-2] so instead of carrying a whole array we can just carry these two values 
int maxi(vector<int> &nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1) take+=prev2;
        int notTake=0+prev;

        int curr=max(take,notTake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}


If the first and last house are adjacent -> circular arrangement
1. find max by leaving the last element 
2. find max by leaving the first element
3. return the max of both the answer
int maxi(vector<int> &vect){
    int n=vect.size();
    int prev=vect[0];
    int prev2=0;
    for(int i=1;i<n;i++){
      int take=vect[i];
      if(i>1) take+=prev2;
      int notTake=0+prev;
      int curr=max(take,notTake);
      prev2=prev;
      prev=curr;
    }
    return prev;
    }
int main(vector<int>&arr){
 vector<int> temp1,temp2;
 int n=arr.size();
 if(n==1)return arr[0];
 for(int i=0;i<n;i++){
    if(i!=0) temp1.push_back(arr[i]);
    if(i!=n-1)temp2.push_back(arr[i]);
 }
 return max(maxi(temp1), maxi(temp2));
}
*/
int main()
{ 
/* 
State: A subproblem that we want to solve. The subproblem may be complex
or easy to solve but the final aim is to solve the final problem which may be 
defined by a relation between the smaller subproblems. Represented with some parameters.

Transition: Calculating the answer for a state (subproblem) by using the answers of other smaller states
(subproblems). Represented as a relation b/w states.

eg:- fibonacci problem
state:- dp[i] or f(i) meaning ith fibonacci number
transition:- dp[i]=dp[i-1]+dp[i-2];
*/
 
 return 0;
}