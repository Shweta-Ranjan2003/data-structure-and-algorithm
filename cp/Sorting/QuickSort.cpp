#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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
void qs(vector<int>&arr, int s, int e){
    if(s>=e)return;
    int p=partition(arr,s,e);
    qs(arr,s,p-1);
    qs(arr,p+1,e);
    return;
}
int getRandom(int a,int b){
    return (rand()%(b-a+1))+a ;
}
void randomize(vector<int>& arr){
    int n=arr.size();
    for(int i=n-1;i>0;i--){
        int r=getRandom(0,i-1);
        swap(arr[i],arr[r]);
    }
}
int main()
{ 
 vector<int>arr{1,2,3,4,5,7,8,9,10}; //worst case
 //qs(arr,0,9);
//  for(auto it:arr){
//     cout<<it<<" ";
//  }

//  for(int i=0;i<5;i++){
//     cout<<getRandom(50,100)<<" ";
//  }
randomize(arr);
 for(auto it:arr){
    cout<<it<<" ";
 }

 return 0;
}