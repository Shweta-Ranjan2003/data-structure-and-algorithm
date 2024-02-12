#include <iostream>
using namespace std;

int sq(int n){
    for(int i=1;i*i<=n;i++){
        if(i*i==n)return i;
    }
    return 0;
}
float square(int n , int precision){
    int start=0;
    int end=n;
    int mid;
    float ans;
    while(start<=end){
        mid=(start+end)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        if(mid*mid<n){
            start=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;
        }
    }
    float increment=0.1;
    for(int i=0;i<precision;i++){
        while(ans*ans<=n){
            ans+=increment;
        }
        ans=ans-increment;
        increment=increment/10;
    }
    return ans;
}
int main()
{ 
 cout<<sq(4)<<endl;
 cout<<square(10,3);
 return 0;
}