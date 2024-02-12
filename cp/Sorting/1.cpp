#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
O(N^2)
Bubble sort
Selection sort
Insertion sort

O(NlogN)
Merge sort
Quick sort - Worst case O(N^2)
Heap sort

Bucket sort - When range is less and no. of element is very big like jee rank list
Counting sort
Radix sort
*/
//Learn about Functional object functr
//K closest cab from origin out of N cabs
class cab{
    public:
    int x;
    int y;
    cab(int a,int b){
        x=a;
        y=b;
    }
};
class cabcomp{
    public:
    bool operator()(cab a,cab b){
        return (abs(a.x)+abs(b.y)) > (abs(a.x)+abs(b.y));
    }
};
bool comp(const pair<int,int> &a,
              const pair<int,int> &b){
    return abs(a.first)+abs(a.second) < abs(b.first)+abs(b.second);
}
int main()
{ 
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x;
        cin>>y;
        vec.push_back({x,y});

    }
    sort(vec.begin(),vec.end(),comp); //custom comparator
    cout<<"Nearest K cabs are"<<endl;
    for(int i=0;i<k;i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }

    //Using pq
    priority_queue<cab,vector<cab>,cabcomp>pq;
    cab a(20,35);
    cab b(20,15);
    cab c(20,0);
    cab d(20,10);
    cab e(0,0);
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    while(!pq.empty()){
        cab x=pq.top();
        cout<<x.x<<" "<<x.y<<endl;
        pq.pop();
    }
 return 0;
}