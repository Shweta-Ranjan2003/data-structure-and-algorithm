#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Find Unique element in sorted array of size 2N+1 element
1,1,2,2,4,4,7,7,8,10,10,12,12
return 8;
*/
int main()
{ 
 int n;
 cin>>n;
 vector<int>nums(n);
 for(int i=0;i<n;i++){
    cin>>nums[i];
 }
        int i=0;
        int j=n-1;
        int mid;
        while(i<=j){
          mid=(i+j)/2;
          if(mid!=0 and nums[mid]==nums[mid-1]){
              int left=mid-i;
              if((left%2)==0){
                  j=mid-2;
              }
              else{
                  i=mid+1;
              }
          }
          else if(mid!=n-1 and  nums[mid]==nums[mid+1]){
              int right=j-mid;
              if((right%2)==0){
                  i=mid+2;
              }
              else{
                  j=mid-1;
              }
          }
          else break;
        }
  cout<<nums[mid];
 return 0;
}