#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
/*
Binary number -
1. Binary representation of no.
28 - lcm with 2 if divisible then 0 otherwise 1
2  28
2  14  0
2  7   0
2  3   1
2  1   1
   0   1
= 11100

2. Number from binary = 11100
-> 2^4*1 + 2^3*1 + 2^2*1 + 2^1*0 + 2^0*0 =28

operators
Basic operations
problems
*/

string NumberToBinary(int n){
string ans="";
while(n>0){
    int rem=n%2;
    ans+=to_string(rem);
    n=n/2;
}
reverse(ans.begin(),ans.end());
return ans;
}

/*
11111111 ....
If 32nd bit is 1 it denotes sign bit if it is 1 then number is negative
if its 0 then number is positive

if it would have been 00001111 then it will be 2^4-1 = 15
0111111..... it is INT_MAX it is 2^31-1

if it is 11111.. then to convert it we have to take 2's complement (1's complement+1)
eg - 5=00101
    -5=11010+1 = 11011
    -(-5)=00101

for 4 bits largest positive no. possible is 7 0111 not 8 because 8will take
5 bit to store 01000 not 1000 because in 1000 we cant identify it +ve or -ve
to range gor 4 bit is -8(1000) to 7(0111) 

Thats why when we do lets say 6+2 it will wrap around and give some other no.
because 8 cant be store in 4bit It is called wrap around

INT_MIN is 100000...
*/
int main()
{ 
 cout<<NumberToBinary(28)<<endl; //11100
 cout<<~5<<endl; //-6 -(n+1)
/*
5 - 0101
~5- 1010 (denotes its negative)
value-0101+1=0110 (-6)
*/
 cout<<~10<<endl; //-11 -(n+1)
 unsigned int x=5;
 cout<<(~x)<<endl; //4294967290

 /*
 When << left shift a number it gets multiplied by 2
 a<<1 = a*2^1
 a<<b = a*2^b
When >> right shift
 a>>1 = a/2^1
 a>>b =a/2^b
 */
 return 0;
}