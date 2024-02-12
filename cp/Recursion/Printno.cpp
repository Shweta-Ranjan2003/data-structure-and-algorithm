#include <iostream>
using namespace std;

void inc(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    inc(n-1);
    cout<<n<<" ";
    return;
}
void dec(int n){
    if(n==1){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    dec(n-1);
    return;
}
int main()
{ 
 inc(5);
 cout<<endl;
 dec(5);
 return 0;
}