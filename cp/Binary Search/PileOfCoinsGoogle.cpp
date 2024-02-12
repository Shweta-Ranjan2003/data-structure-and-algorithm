#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
array of n piles , and k friends including you
you have to make cut and distribute array into segments and all k friends
will get sum of one segment coin
you will get minimum sum segment you have to maximize it
*/
int check(vector<int>&piles,int mid,int cuts){
    int n=piles.size();
    int cnt=0;
    for(int i=0;i<n;i++){
    int curr=0;
       while(curr<mid and i<n){
           curr+=piles[i];
           i++;
       }
       i--;
       cnt++;
    }
    if(cnt>=cuts)return 1;
    return 0;
}
int main()
{ 
    vector<int>piles{6,8,4,2,1,7};
    int n=piles.size();
    int low=INT_MAX;
    int high=0;
    for(int i=0;i<n;i++){
        low=min(low,piles[i]);
        high+=piles[i];
    }
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(piles,mid,3)){
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