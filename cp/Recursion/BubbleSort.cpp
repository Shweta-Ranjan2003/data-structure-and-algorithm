#include <bits/stdc++.h>
using namespace std;


void BS2(vector<int>&arr,int n,int i){
    if(n==0||n==1)return;
    if(i==n-1){
        BS2(arr,n-1,0);
        return;
    }
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    BS2(arr,n,i+1);
    return;
}
void BS(int n,vector<int>&arr){
    if(n==1)return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
    }
    BS(n-1,arr);
}
int main(){
    vector<int>arr{5,4,3,2,1};
    int n=arr.size();
    //Iteratively
    // for(int i=0;i<n-1;i++){
    //    for(int j=0;j<n-1-i;j++){
    //     if(arr[j]>arr[j+1]){
    //         swap(arr[j],arr[j+1]);
    //     }
    //    }
    // }

    //One loop in recursion
    // BS(n,arr);

    //No loop in recursion
    BS2(arr,n,0);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}