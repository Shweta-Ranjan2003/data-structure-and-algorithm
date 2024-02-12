#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
BALIFE - SPOJ
We will take prefix sum and check how much it is less than required 
and then take max of ans and required-psum[current] .
Because processor are running in parrallel so if one processor is doing 10 task
and other 5 task then time will be 10 because they work in parallel
*/
int main()
{ 
vector<int>load{16, 17, 15, 0, 20, 1, 1, 2};
 //vector<int>load{0,0,100,0,0,0,0,0,0,0};
 int n=load.size();
 vector<int>psum(n,0);
 psum[0]=load[0];
 int total=load[0];
 for(int i=1;i<n;i++){
    psum[i]=psum[i-1]+load[i];
    total+=load[i];
 }
 int want=total/n;
 if((total%n)!=0)cout<<"-1";
 else{
 int ans=INT_MIN;
 for(int i=0;i<n;i++){
    ans=max(ans,abs((want*(i+1))-psum[i]));
 }
 cout<<ans;
 }
 return 0;
}