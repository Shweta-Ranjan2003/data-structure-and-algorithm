#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
void subsetSums(vector<int>&arr,vector<int>&v,int start,int n){
     int i,j,sum;

    for(i = 0; i < (1<<n); i++) {
            sum = 0;
        for(j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum = sum + arr[j+start];
            }

        }
         v.push_back(sum);
    }
}
int main(){
    long long n;
    cin>>n;
    long long minimum ,maximum;
    cin>>minimum;
    cin>>maximum;
    arr.resize(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>first,second;
    subsetSums(arr,first,0,n/2);
    if(n&1){
    subsetSums(arr,second,(n/2)+1,n/2);
    }
    subsetSums(arr,second,n/2,n/2);
    sort(second.begin(),second.end());
    long long ans=0;
    for(int i=0;i<first.size();i++){
        int it1=lower_bound(second.begin(),second.end(),(minimum-first[i]))-second.begin();
        int it2=upper_bound(second.begin(),second.end(),(maximum-first[i]))-second.begin();
        ans+=(it2-it1);
    }
    cout<<ans;
    return 0;
}