#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Find kth smallest element - k-1 index in sorted array
7 1 2 4 6 3 8
now 4th smallest element will be at index 3 in sorted array
using quick sort we can recursively shorter the search space
like if we pick 3 as pivot we will get 2 elements on left and 3 being the 3rd
smallest now for 4 smallest we only need to sort right array to get 1st
smallest in right side (we did not sort left part)

This is an optimization over method 1, if QuickSort is used as a sorting 
algorithm in first step. In QuickSort, pick a pivot element, then move the 
pivot element to its correct position and partition the surrounding array. 
The idea is, not to do complete quicksort, but stop at the point where pivot 
itself is k’th smallest element. Also, not to recur for both left and right 
sides of pivot, but recur for one of them according to the position of pivot. 
*/
class Solution {
public:
    
    int partition_algo(vector<int>& nums, int L, int R) {
        int P = nums[L];
        int i = L+1; //0
        int j = R; //0
        while(i <= j) {   
            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= P) {
                i++;
            }
            if(nums[j] <= P) {
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j; //P is at jth index
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0;
        int R = n-1;
        int pivot_idx = 0;
        //kth largest pivot element - nums[k-1] (descendinforder me partition karenge)
        while(true) {
             pivot_idx = partition_algo(nums, L, R);
            if(pivot_idx == k-1) {
                break;
            } else if(pivot_idx > k-1) { //2nd larget , 4th larget
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
        }
        return nums[pivot_idx];
    }
};
int main()
{ 
 vector<int>arr{7,2,0,4,8,9,5,9,10}; //worst case
 cout<<kthSmallest(arr,0,8,5)<<endl; //9
 cout<<qs(arr,0,8,5); //9
 return 0;
}