#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//1.Min Max element in array - Traversal
/*
void MinAndMax(int* arr , int size){
    int minimum = *(arr);
    int maximum = *(arr);
    for (int i = 0; i < size; i++)
    {
        if (*(arr+i)>maximum)
        {
            maximum = *(arr+i);
        }
        if (*(arr+i)<minimum)
        {
            minimum = *(arr+i);
        }
        
    }
    cout<<"Minimum element is : "<<minimum<<endl;
    cout<<"Maximum element is : "<<maximum<<endl;
    
}
int main()
{ 
 int input;
 cin>>input;
 int ar[input];
 for (int i = 0; i < input; i++)
 {
    cin>>ar[i];
 }
 int size = sizeof(ar)/sizeof(ar[0]);  // how to calculate size of array
 MinAndMax(ar,size);
 return 0;
}
*/

//2. Reverse an array
/*
void Reverse(int arr[] , int size){
    int temp;
    for (int i = (size-1); i >= 0; i--)
    {
            cout<<arr[i]<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= (size/2); i++)
    {
        temp = arr[i-1];
        arr[i-1]= arr[(size-i)];
        arr[(size-i)] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main(){
    int input;
    cin>>input;
    int arr[input];
    for (int i = 0; i < input; i++)
    {
        cin>>arr[i];
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    Reverse(arr , size);
    
    return 0;
}
*/

//3. Maximum Subarray :- KADANE'S ALGORITHM
/*
int MaxSubarray(int ary[] , int size){
    int max_sum = ary[0];
    int current_sum = max_sum;
    for (int i = 1; i < size; i++)
    {
        current_sum = max(current_sum + ary[i] , ary[i]);
        max_sum = max(max_sum , current_sum);
    }
    return max_sum;
}
int main(){
    int size;
    cin>>size;
    int ary[size];
    for (int i = 0; i < size; i++)
    {
        cin>>ary[i];
    }
    int maxsum = MaxSubarray(ary,size);
    cout<<maxsum;
    return 0;
}
*/

//4. Contains duplicate
/*
bool containsDuplicate(vector<int>& arry) {
        unordered_set<int> myset;
        for(int i = 0 ; i<arry.size(); i++){
            if(myset.find(arry[i]) != myset.end()){
                return true;
            }
            else
            myset.insert(arry[i]);
        }
        return false;
    }
    // Contains duplicate in sorted array
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0 ; i< (nums.size()-1); i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
                i= -1;
            }
            else continue;
        }
        int k = nums.size();
        return k;
    }
int main(){
    int size;
    cin>>size;
    int value;
    vector<int> vec1(size);
    for (int i = 0; i < size; i++)
    {
        cin>>vec1[i];
    }
    // vec1.push_back(5);
    if (containsDuplicate(vec1))
    {
        cout<<"True";
    }
    else
    cout<<"False";
    
    return 0;
}
*/

//5. Chocolate distribution problem
/*
// Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m(no. of students) = 5  Output: Minimum Difference is 6 
// arr[] = {1,3,4,7,9,9,12,56}
int mindiff(vector<int> &a , int m){
    sort(a.begin(), a.end());
    int mini = a[(0+m)-1]-a[0];
    for (int i = 1; (i+m)-1<a.size(); i++)
    {
        mini = min(mini , (a[(i+m)-1]-a[i]));
    }
    return mini;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int min = mindiff(a,m);
    cout<<min;
    return 0;
}
*/

//6. Search in rotated sorted array - Binary search
//Input: nums = [4,5,6,7,0,1,2], target = 0   Output: 4
//Input: nums = [8,9,10,0,1,2,3,4,5], target = 10   Output: 2
/*
int search(vector<int>& a, int target) {
    int beg = 0;
    int end = a.size()-1;
    while (beg<=end)
    {
        int mid = (beg+end)/2;
        if (a[mid] == target)
        {
            return mid;
        }
        // left side is sorted
        if (a[beg]<=a[mid])
        {
            if (target>=a[beg]&& target <= a[mid])
            {
                end = mid -1;   
            }
            else{
                beg = mid+1;
            }
         }
        else{
            if(target>=a[mid]&&target<=a[end]){
              beg = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
    }
int main(){
    int size;
    cin>>size;
    vector<int> arrr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arrr[i];
    }
    int target;
    cin>>target;
    int result = search(arrr , target);
    cout<<result;
    return 0;
}
*/
 
 //7. check-if-array-is-sorted-and-rotated
 /*
 bool check(vector<int>& nums) {
        int x=0 , y=0;
        for(int i = 0 ; i<(nums.size()-1); i++){
            if(nums[i]<=nums[i+1]){
                x++;
            }
            else y++;
    }
    if(y==1){
        if(nums[(nums.size()-1)]<=nums[0]){
            x++;
        }
        else y++;
    }
    if(y==1 || y==0){
        return true;
    }
    else return false;
    }
    int main(){
        vector<int> vec;
        int x;
        for (int i = 0; i < 5; i++)
        {
            cin>>x;
            vec.push_back(x);
        }
        bool sortedORrotated = check(vec);
        cout<<sortedORrotated<<endl;
        return 0;
    }
    */