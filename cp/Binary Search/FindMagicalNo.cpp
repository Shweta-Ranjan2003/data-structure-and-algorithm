#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Find Ath magical no. (natural no.)
a no is magical if it is divisible by B or C
A=8
B=2
C=3
*/
long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 
int main()
{ 
 int a,b,c;
 cin>>a;
 cin>>b;
 cin>>c;
 int low=1;
 int high=a*(min(b,c));
 while(low<=high){
    int mid=(low+high)/2;
    int tLeft=(mid/b)+(mid/c)-(mid/lcm(b,c));
    if(tLeft==a){
        cout<<mid;
        break;
    }
    if(tLeft<a){
        low=mid+1;
    }
    if(tLeft>a){
        high=mid-1;
    }
 }
 return 0;
}