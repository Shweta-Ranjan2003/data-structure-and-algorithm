#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
1. Ek O - spoj
2. Painter partition problem
3. book allocation problem
*/

//Painter Parition problem
bool check(int mid,vector<int> &boards,int k){
    int n = boards.size();
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= mid) {
            boardsPainter += boards[i];
        }
        else {
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters<=k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=INT_MIN;
    int high=0;
    int n=boards.size();
    for(int i=0;i<n;i++){
        low=max(low,boards[i]);
        high+=boards[i];
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,boards,k)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

//Book allocation problem
bool check2(int mid,int arr[], int m,int n){
        int cnt=1;
        int curr=0;
        for(int i=0;i<n;i++){
            if(arr[i]+curr<=mid){
                curr+=arr[i];
            }
            else{
                cnt++;
                curr=arr[i];
            }
        }
        if(cnt<=m){
            return true;
        }
        return false;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n)return -1;
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<n;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(check2(mid,arr,m,n)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }

//Eko Spoj
bool possible(int mid,vector<int>&trees,int wood){
    int cnt=0;
    int n=trees.size();
    for(int i=0;i<n;i++){
        if(trees[i]>mid){
            cnt+=(trees[i]-mid);
        }
    }
    return cnt>=wood;
}
int main()
{ 
 int tree;
 cin>>tree;
 int wood;
 cin>>wood;
 vector<int>sizee(tree);
 for(int i=0;i<tree;i++){
    cin>>sizee[i];
 }
 int low=1;
 int high=INT_MIN;
 for(int i=0;i<tree;i++){
    high=max(high,sizee[i]);
 }
 int ans=low;
 while(low<=high){
    int mid=(low+high)/2;
    if(possible(mid,sizee,wood)){
        ans=mid;
        low=mid+1;
    }
    else{
        high=mid-1;
    }
 }
 cout<<ans;
 return 0;
}