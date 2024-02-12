#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Running Median - lc 295
i/p - 5,7,1,8,6,2,0,-1
o/p - 5,5,5,5,6,5,5,2

5  5,7  1,5,7  1,5,7,8  1,5,6,7,8 

observation- we can balance two heaps with size n,n or 
n+1,n(median=element from left heap) or n,n+1(median from right heap)
But how to maintain two heap in sorted order?
Take left heap is max heap and right as a min heap
so when you insert 6 in eg
max heap = 1,5
min heap = 7,8
insert 6 to right heap because its greater then prev median 5

When heap size differ more than one element then do shifting between heap
*/

int main()
{ 
 int n;
 cin>>n;
 vector<int>vec;
 for(int i=0;i<n;i++){
    int element;
    cin>>element;
    vec.push_back(element);
 }
 vector<int>ans;
 priority_queue<int>max_heap;
 priority_queue<int,vector<int>,greater<int>> min_heap;

int median=vec[0];
ans.push_back(median);
max_heap.push(median);
 for(int i=1;i<n;i++){
  if(vec[i]<median){
      max_heap.push(vec[i]);
      if(max_heap.size()==min_heap.size()){
        ans.push_back(max_heap.top());
        median=max_heap.top();
        continue;
    }
      while(max_heap.size()>min_heap.size()+1){
        int element=max_heap.top();
        max_heap.pop();
        min_heap.push(element);
      }
      ans.push_back(max_heap.top());
      median=max_heap.top();
  }
  else{
    min_heap.push(vec[i]);
      while(min_heap.size()>max_heap.size()+1){
        int element=min_heap.top();
        min_heap.pop();
        max_heap.push(element);
      }
    if(max_heap.size()==min_heap.size()){
        ans.push_back(max_heap.top());
        median=max_heap.top();
        continue;
    }
      ans.push_back(min_heap.top());
      median=min_heap.top();
  }
 }
 for(auto it:ans){
    cout<<it<<" ";
 }
 return 0;
}
//Clean code -
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    vector<int> ans(n);
    ans[0]=v[0];
    max_heap.push(v[0]);
    int median=v[0];
    for(int i=1;i<n;i++){
        if(v[i]<median){
            max_heap.push(v[i]);
        }
        else{
            min_heap.push(v[i]);
        }
        int x=max_heap.size();
        int y=min_heap.size();
        if(abs(x-y)>1){
            if(x>y){
                int p=max_heap.top();
                max_heap.pop();
                min_heap.push(p);
            }
            else{
                int p=min_heap.top();
                min_heap.pop();
                max_heap.push(p);
            }
        }
        if(max_heap.size()==min_heap.size()){
            // median=(max_heap.top()+min_heap.top())/2;
             median=max_heap.top();
        }
        else if(max_heap.size()>min_heap.size()){
            median=max_heap.top();
        }
        else median=min_heap.top();
        ans[i]=median;
    }
    for(int i:ans) cout<<i<<" ";
    return 0;
}
*/