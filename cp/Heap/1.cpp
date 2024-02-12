#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Heap - 1. complete binary tree (all level completely filled , except last level)
       filling must be in left to right order
       2. Heap order property - max heap (node>=children) , min heap(node<=children)
*/
class heap{
public:
vector<int>arr;
heap(){
arr.push_back(-1);
}
void push(int data){
  int n=arr.size();
  arr.push_back(data);
  int curr=n;
  while(curr>1){
    if(arr[curr]>arr[curr/2]){
        swap(arr[curr],arr[curr/2]);
        curr=curr/2;
    }
    else break;
  }
}
int top(){
    return arr[1];
}
void heapify(int ind){
    int n=arr.size();
    while(ind<n){
    int left=2*ind;
    int right=left+1;
    if(left<n && right<n){
        if(arr[left]>arr[ind] && arr[left]>arr[right]){
            swap(arr[left],arr[ind]);
            ind=left;
        }
        else if(arr[right]>arr[ind]){
            swap(arr[right],arr[ind]);
            ind=right;
        }
    }
    else if(left<n && arr[left]>arr[ind]){
        swap(arr[left],arr[ind]);
        ind=left;
    }
    else break;
    }
}
void pop(){
    int n=arr.size();
    swap(arr[1],arr[n-1]);
    arr.pop_back();
    heapify(1);
}
void print(){
    int n=arr.size();
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
};
int main()
{ 
 heap h;
 int s;
 cin>>s;
 for(int i=0;i<s;i++){
    int x;
    cin>>x;
    h.push(x);
 }
 //h.print();
 //cout<<endl;
 h.pop();
 h.print();
 return 0;
}