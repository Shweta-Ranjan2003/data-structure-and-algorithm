#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
/*
Two sum
n distinct elements find pair whose sum is k
1. Brute n^2
2. Sort - NlogN
3. Set - O(N)
*/
void Twosum(vector<int>&arr,int k,vector<vector<int>>&ans){
unordered_set<int>st;
for(auto x:arr){
    if(st.count(k-x)){
         vector<int>temp;
         temp.push_back(x);
         temp.push_back(k-x);
         ans.push_back(temp);
    }
    st.insert(x);
}
return;
}

/*
N Distinct sorted elements
where a[j]-a[i]=k
k=5
-3,0,1,3,6,8,11,14,20,25
use 2 pointer
*/

void Twosum2(vector<int>&arr,int k,vector<vector<int>>&ans){
int s=0;
int e=1;
int n=arr.size();
while(e<n){
    if(arr[e]-arr[s]<k){
      e++;
    }
    else if(arr[e]-arr[s]>k){
        s++;
    }
    else{
        vector<int>temp;
        temp.push_back(arr[s]);
        temp.push_back(arr[e]);
        ans.push_back(temp);
        s++;
        e++;
    }
}
return;
}

/* *******Check it**********
Triplet Sum but condition a[i]+a[j]+a[k]<=sum
*/
int Twosum3(vector<int>&arr,int k){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<=n-3;i++){
        int sum=k-arr[i];
        int s=i+1;
        int e=n-1;
        while(s<e){
        if(arr[e]+arr[s]<=sum){
          cnt+=e-s;
          s++;
        }
        else{
            e--;
        }
        }
    }
return cnt;
}

/* Leetcode 11
Array denoting height of building , tell max water that can be trapped between two building
*/
int water(vector<int>&arr){
    int n=arr.size();
    int i=0;
    int j=n-1;
    int ans=INT_MIN;
    while(i<j){
       ans=max(ans,(min(arr[i],arr[j]))*(j-i));
       if(arr[i]<arr[j])i++;
       else if(arr[j]<arr[i])j--;
       else{
          i++;
          j--;
       }
    }
    return ans;
}
int main()
{ 
//  vector<vector<int>>ans;
//  vector<int>arr{5,1,3,8,7,2,6,9};
//  Twosum(arr,14,ans);
//  for(int i=0;i<ans.size();i++){
//     for(int j=0;j<2;j++){
//        cout<<ans[i][j]<<" ";
//     }
//     cout<<endl;
//  }
//  vector<vector<int>>ans;
//  vector<int>arr{-3,0,1,3,6,8,11,14,20,25};
//  Twosum2(arr,5,ans);
//  for(int i=0;i<ans.size();i++){
//     for(int j=0;j<2;j++){
//        cout<<ans[i][j]<<" ";
//     }
//     cout<<endl;
//  }

// vector<int>arr{2,1,4,6,3,8,7};
// cout<<Twosum3(arr,11);

 return 0;
}