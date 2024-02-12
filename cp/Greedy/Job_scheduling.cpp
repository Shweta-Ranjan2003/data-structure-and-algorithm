#include <bits/stdc++.h>
using namespace std;
/*
Job Scheduling - gfg 
Task Deadline  Payment
A     3        100
B     1        19
C     2        27
D     1        25
E     3        30

max= 157 (A,C,E);
*/

int main(){
   int n;
   cin>>n;
   vector<pair<int,int>>vec;
   for(int i=0;i<n;i++){
    int deadline;
    cin>>deadline;
    int payment;
    cin>>payment;
    vec.push_back({deadline,payment});
   }
   sort(vec.begin(),vec.end());
   priority_queue <int, vector<int>, greater<int> > pq; 
   for(auto it:vec){
    if(it.first>pq.size()){
      pq.push(it.second);
    }
    else if(it.first==pq.size()){
        if(it.second>pq.top()){
            pq.pop();
            pq.push(it.second);
        }
    }
   }
   int total=0;
   while(!pq.empty()){
    total+=pq.top();
    pq.pop();
   }
   cout<<total;
    return 0;
}