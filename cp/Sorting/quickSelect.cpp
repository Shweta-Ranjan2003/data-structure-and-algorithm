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
int partition(vector<int>&arr,int s,int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[e],arr[i+1]);
    return i+1;
}
int kthSmallest(vector<int>&arr, int l, int r, int K)
{
    if (K > 0 && K <= r - l + 1) {
        int pos = partition(arr, l, r);
        if (pos - l == K - 1) return arr[pos];
        if (pos - l > K - 1)  return kthSmallest(arr, l, pos - 1, K);
        return kthSmallest(arr, pos + 1, r, K - (pos + l) - 1);
    }
 return INT_MAX;
}
int qs(vector<int>&arr,int l , int r,int k){
    if(l<=r){
        int pivot=partition(arr,l,r);
        if(pivot==k-1) return arr[pivot];
        else if(pivot<k-1){
            return qs(arr,pivot+1,r,k);
        }
        return qs(arr,l,pivot-1,k);
    }
}
int main()
{ 
 vector<int>arr{7,2,0,4,8,9,5,9,10}; //worst case
 cout<<kthSmallest(arr,0,8,5)<<endl; //9
 cout<<qs(arr,0,8,5); //9
 return 0;
}