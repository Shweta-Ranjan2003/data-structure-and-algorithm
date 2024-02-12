#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
Nearest smallest on left or right , largest on left or right
1. 
Nearest Smallest no. of left
Given an array of integer return array where nearest left smallest no. of each element is return
*/
void one(vector<int>&arr,vector<int>&ans){
stack<int>st;
int n=arr.size();
ans.push_back(-1);
st.push(arr[0]);
for(int i=1;i<n;i++){
    while(!st.empty() && arr[i]<=st.top()){
        st.pop();
    }
    if(st.empty()) ans.push_back(-1);
    else ans.push_back(st.top());
    st.push(arr[i]);
}
return;
}

/*
Stock span problem
100 80 120 70 60 75 85
1   1  3   1  1  3  4
*/
void two(vector<int>&arr,vector<int>&ans){
    stack<int>st;
    int n=arr.size();
    st.push(0);
    ans.push_back(1);
    for(int i=1;i<n;i++){
        if(arr[i]<arr[st.top()]){
            ans.push_back(1);
            st.push(i);
        }
        else{
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(i+1);
            else ans.push_back(i-st.top());
            st.push(i);
        }
    }
    return;
}

/* HW
1. Maximum subarray sum (array contains + and -)
2. Histogram area - area of largest size area that can be formed - Leetcode 84
3. 2-D array maximum area of the rectangle with all one that can be formed - Leetcode 85
*/

//One
int maxSubArray(vector<int>& ary){
    int max_sum = ary[0];
    int current_sum = max_sum;
    for (int i = 1; i < ary.size(); i++)
    {
        current_sum = max(current_sum + ary[i] , ary[i]);
        max_sum = max(max_sum , current_sum);
    }
    return max_sum;
}

//Two
vector<int> nextSmaller(vector<int>&height){
        int n=height.size();
        stack<int>st;
        vector<int>next;
        for(int i=n-1;i>=0;i--){
        while(!st.empty() and height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()){
            next.push_back(n);
        }
        else{
            next.push_back(st.top());
        }
        st.push(i);
        }
        reverse(next.begin(),next.end());
        return next;
    }
    vector<int> prevSmaller(vector<int>&height){
        int n=height.size();
        stack<int>st;
        vector<int>prev;
        for(int i=0;i<n;i++){
            while(!st.empty() and height[st.top()]>=height[i]){
                st.pop();
            }
            if(st.empty()){
                prev.push_back(-1);
            }
            else{
            prev.push_back(st.top());
        }
            st.push(i);
        }
        return prev;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next;
        next=nextSmaller(heights);
        vector<int>prev;
        prev=prevSmaller(heights);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int gap=(next[i]-prev[i])-1;
            ans=max(ans,(heights[i]*gap));
        }
        return ans;
    }

//Three 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>prefixSum(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            int curr=0;
            for(int j=0;j<n;j++){
            if(matrix[j][i]=='0'){
             curr=0;
            prefixSum[j][i]=curr;
            }
            else{
               curr++;
               prefixSum[j][i]=curr;
            }
            }
        }
        int ans=INT_MIN;
        for(int i=n-1;i>=0;i--){
             ans=max(ans,largestRectangleArea(prefixSum[i]));
        }
        return ans;
    }

int main()
{ 
 //vector<int> arr{1,6,4,12,3,8};
 //vector<int>ans;
 //one(arr,ans);

 vector<int>arr{100,80,120,70,60,75,85};
 vector<int>ans;
 two(arr,ans);
 for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
 }
 return 0;
}