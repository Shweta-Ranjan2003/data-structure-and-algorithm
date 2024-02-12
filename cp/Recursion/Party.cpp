#include <iostream>
using namespace std;
/*
Friends Pairing Problem - gfg
N friends goes to party -> Solo or couple 
return no. of ways
*/

int ways(int n){
if(n==1)return 1;
if(n==2)return 2;
return (1*ways(n-1)+(n-1)*ways(n-2));
}
/*
Eg - ABC
either this
if A goes alone then going alone is 1 way and others can go in ways(n-1) ways
or this 
if A goes as a couple the he can couple in (n-1)options/ways and rest people will go in ways(n-2) ways
*/

int main()
{ 
 cout<<ways(3);
 return 0;
}