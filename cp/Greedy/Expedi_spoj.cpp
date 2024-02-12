#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//871. Minimum Number of Refueling Stops

int main()
{ 
 int n;
 cin>>n;
 vector<pair<int,int>>vec;
 for(int i=0;i<n;i++){
  int dist;
  cin>>dist;
  int fuel;
  cin>>fuel;
  vec.push_back({dist,fuel});
 }
 int town_dist;
 cin>>town_dist;
 int current_fuel;
 cin>>current_fuel;
 for(int i=0;i<n;i++){
    vec[i].first=town_dist-vec[i].first;
 }
 sort(vec.begin(),vec.end());

 int cnt=0;
 int i=0;
 priority_queue<int>pq;
 int last_dist=0;
 while(i<n){
    if(current_fuel<(vec[i].first-last_dist)){
        while(current_fuel<(vec[i].first-last_dist) && !pq.empty()){
               current_fuel+=pq.top();
               pq.pop();
               cnt++;
        }
        if(current_fuel<(vec[i].first-last_dist)){
            cout<<-1;
            return 0;
        }
    }
    else{
      current_fuel=current_fuel-(vec[i].first-last_dist);
      last_dist=vec[i].first;
      pq.push(vec[i].second);
      i++;
    }
 }
 if(current_fuel>=(town_dist-last_dist)){
    cout<<cnt;
    return 0;
 }
 while(current_fuel<(town_dist-last_dist) && !pq.empty()){
    current_fuel+=pq.top();
    cnt++;
    pq.pop();
 }
 if(current_fuel<(town_dist-last_dist)){
    cout<<-1;
    return 0;
 }
 cout<<cnt;
 return 0;
}