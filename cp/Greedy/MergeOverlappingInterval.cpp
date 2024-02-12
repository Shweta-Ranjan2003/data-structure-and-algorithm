#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Merge overlapping Interval  - 56
[1,4] [2,5] [6,8] [10,12] [6,10]
o/p = [1,5] [6,12]
*/
int main()
{ 
 int n;
 cin>>n;
 vector<pair<int,int>>vec;
 for(int i=0;i<n;i++){
    int s;
    cin>>s;
    int e;
    cin>>e;
    vec.push_back({s,e});
 }
 sort(vec.begin(),vec.end());
 vector<int>temp;
 temp.push_back(vec[0].first);
 int last=vec[0].second;
 vector<vector<int>>ans;
 for(int i=1;i<n;i++){
   if(vec[i].first<=last){
    last=max(last,vec[i].second);
   }
   else{
    temp.push_back(last);
    ans.push_back(temp);
    temp.clear();
    temp.push_back(vec[i].first);
    last=vec[i].second;
   }
 }
 temp.push_back(last);
ans.push_back(temp);
 for(int i=0;i<ans.size();i++){
    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
 }
 return 0;
}