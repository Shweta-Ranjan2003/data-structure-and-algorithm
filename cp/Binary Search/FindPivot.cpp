#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Find smallest element in a rotated sorted array
*/
int main()
{ 
 vector<int>ans{2,3,4,5,0,1};
 int n=ans.size();
 int low=0;
 int high=n-1;
 while(low<=high){
    int mid=(low+high)/2;
    if(mid<n-1 && mid>0 && ans[mid]>ans[mid+1] && ans[mid]>ans[mid-1]){
        cout<<ans[mid+1];
        return 0;
    }
    if(mid<n-1 && mid>0 && ans[mid]<ans[mid-1] && ans[mid]<ans[mid+1]){
        cout<<ans[mid];
        return 0;
    }
    if(ans[mid]>ans[low]){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
 }
 cout<<ans[low];
 return 0;
}