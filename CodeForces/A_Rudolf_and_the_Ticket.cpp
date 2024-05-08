#include <bits/stdc++.h>
using namespace std;
int main()
{ 
 int t;
 cin>>t;
 while(t){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int k;
    cin>>k;
    vector<int>left(n);
    for(int i=0;i<n;i++){
       cin>>left[i];
    }
    vector<int>right(m);
    for(int i=0;i<m;i++){
        cin>>right[i];
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    int i=0;
    int j=m-1;
    int ways=0;
    while(i<n and j>=0){
      if(left[i]+right[j]<=k){
        ways+=(j+1);
        i++;
      }
      else{
        j--;
      }
    }
    cout<<ways<<endl;
    t--;
 }
 return 0;
}