#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int precomp[200001];
void precompute(){
    for(int i=1;i<=200000;i++){
        int sum=0;
        int no=i;
        while(no){
            sum+=(no%10);
            no=no/10;
        }
        precomp[i]=precomp[i-1]+sum;
    }
}
int main()
{ 
 int t;
 cin>>t;
 precompute();
 while(t){
    int n;
    cin>>n;
    cout<<precomp[n]<<endl;
    t--;
 }
 return 0;
}