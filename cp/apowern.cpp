#include <iostream>
using namespace std;
//Calculate a^n 

int recur(int a,int n){
    if(n==1)return a;

    return a*recur(a,n-1);
}
int calc(int a,int n){
    int ans=1;
    while(n>0){
        if(n&1){
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    return ans;
}
int main()
{ 
 cout<<recur(5,4)<<endl;
 cout<<calc(5,4);
 return 0;
}