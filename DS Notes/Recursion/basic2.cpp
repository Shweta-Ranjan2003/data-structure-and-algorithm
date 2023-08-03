#include <iostream>
using namespace std;
/*
******Multiple recursion call********
A subarray is a contiguous part of array and maintains relative ordering of elements. 
For an array/string of size n, there are n*(n+1)/2 non-empty subarrays/substrings.

A subsequence maintain relative ordering of elements but may or may not be a contiguous part of an array. 
For a sequence of size n, we can have 2^n-1 non-empty sub-sequences in total.

A subset MAY NOT maintain relative ordering of elements and can or cannot be a contiguous part of an array. 
For a set of size n, we can have (2^n) sub-sets in total.
when we find subset of a set we dont take a subset which is a permutation
example {1,2,3}:
{2,1} and {1,2} are the same thing that is {2,1} is permutation of {1,2}--> so we count it only once
*/

/*
******SUBSETS********
1. If we have subsets of A -> [] (not picking A) , [A] (picking A) then we can make subsets of AB by picking or not picking B
in every subset of A , AB -> [] (not picking B) , [B] (picking B) , [A] (not picking B) , [AB] (picking B). same for ABC-> 
[],[C],[B],[BC],[A],[AC],[AB],[ABC].

void subsets(string s, string curr,int ind){
 if(ind==s.size()){
    cout<<curr;
    return;
 }
 //not picking
 subsets(s,curr,ind+1);
 //picking
 subsets(s,curr+s[ind],ind+1);
}

**********Subset – II | Print all the Unique Subsets*********
void subset(int ind, int n,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
    
    for(int i=ind;i<n;i++){
        if(i!=ind&&nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        subset(i+1,n,nums,ds,ans);
        ds.pop_back();
    }
}
*/


/*
********PRINT ALL SUBSEQUENCE*********
2. Same as printing subsets . But if we want to store it in a data structure then we need to do one more thing that is
pop out the element after the recursion for pick returns and not pick recursion begins. We did not did it in subset code
above because there we used curr string which value is passed by value but here we will make change in data structure 
which will be passed by reference.

void subsequence(int ind , int n ,vector<int>&ds , vector<vector<int>>&ans, int arr[]){
    if(ind==n){
        ans.push_back(ds);
        return;
    }

    //picking
    ds.push_back(arr[ind]);
    subsequence(ind+1,n,ds,ans,arr);
    ds.pop_back();

    //not picking
    subsequence(ind+1,n,ds,ans,arr);
}

OR PRINT ALL SUBSEQUENCE WITH SUM TARGET
void subsequence(int ind , int n , int sum , int target ,int arr[] , vector<int>&ds ,vector<vector<int>&ans){
    if(ind==n){
       if(sum==target) ans.push_back(ds);
        return;
    }

    //picking
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    subsequence(ind+1,n,sum,target,arr,ds,ans);
    sum-=arr[ind];
    ds.pop_back();

    //not picking
    subsequence(ind+1,n,sum,target,arr,ds,ans);
}
*/


/*
**********MERGE SORT**********
3. Merge Sort is a divide and conquers algorithm, it divides the given array into equal parts and then merges the 2 sorted parts. 
There are 2 main functions :
merge(): This function is used to merge the 2 halves of the array. It assumes that both parts of the array are sorted 
and merges both of them using two pointer approch.
mergeSort(): This function divides the array into 2 parts. low to mid and mid+1 to high.

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;    
    int right = mid + 1; 

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}
*/


/*
********QUICK SORT********
4. Pick a pivot and place it in its correct place in the sorted array.
Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}
*/


/*
**************PERMUTATIONS************
5. Maintain a frequency array which maintains the status of element whether it is picked or not
void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }

Or more optimal approach - 
void recur(int index,vector<int> &nums,vector<vector<int>> &ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        recur(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}

*/


/*
***********COMBINATION SUM***********
- The same number may be chosen from candidates an unlimited number of times
void fc(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    //pick up the element
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        fc(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
    fc(ind+1,target,arr,ans,ds);
}

- The same number may be chosed from candidates only once
void fc(int ind,int target,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
     if(target==0){
         ans.push_back(ds);
         return;
     }
     for(int i=ind;i<arr.size();i++){
         if(i>ind&&arr[i]==arr[i-1]) continue;
         if(arr[i]>target) break;
         ds.push_back(arr[i]);
         fc(i+1,target-arr[i],arr,ds,ans);
         ds.pop_back();
     }
}
*/
int main()
{ 
 
 return 0;
}