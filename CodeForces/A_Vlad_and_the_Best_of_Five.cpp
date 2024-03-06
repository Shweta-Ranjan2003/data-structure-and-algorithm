#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        int a=0;
        int b=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='A')a++;
            else b++;
        }
        if(a>b)cout<<'A'<<endl;
        else cout<<'B'<<endl;
    }
    return 0;
}