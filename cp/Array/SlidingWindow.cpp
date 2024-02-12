#include <iostream>
#include <vector>
using namespace std;
/*
1. Find max sum of a subarray of length k
2. Given array of acres find minimum length subarray whose sum is at least k
*/
int two(vector<int>&nums,int target){
    int start=0;
        int end=0;
        int n=nums.size();
        int sum=0;
        int ans=INT_MAX;
        while(end<n){
            sum+=nums[end];
            while(sum>=target){
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return ans==INT_MAX? 0:ans;
}


int main()
{ 
 vector<int>arr{1,3,2,1,4,1,3,2,1,6,2};
 cout<<two(arr,8);
 return 0;
}