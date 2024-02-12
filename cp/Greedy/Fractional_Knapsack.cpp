#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Fractional Knapsack - gfg
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. 
*/
bool Comp(pair<int,int>& a,pair<int,int>& b){
    float unit_price1=a.first/a.second;
    float unit_price2=b.first/b.second;
    return unit_price1>unit_price2;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n); //amount,weight(quantity)
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int W;
    cin>>W;
    sort(v.begin(),v.end(),Comp);
    vector<int> unit_prices(n);
    for(int i=0;i<n;i++){
        unit_prices[i]=v[i].first/v[i].second;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i].second<=W){
            ans+=v[i].first;
            W=W-v[i].second;
        }
        else{
            ans+=unit_prices[i]*W;
        }
    }
    cout<<ans;
    return 0;
}