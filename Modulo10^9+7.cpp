#include <iostream>
using namespace std;
/* MODULO ARITHMETIC
(a+b)%M = ((a%M)+(b%M))%M
(a*b)%M = ((a%M)*(b%M))%M
(a-b)%M = ((a%M)-(b%M)+M)%M
(a/b)%M = ((a%M)*(b^-1)%M)%M   (b^-1 is multiplication inverse)
*/
int main()
{ 
 //Given a number N. Print its factorial. Constrainsts 1<=N<=100
 // Print answer module M where M=47.
 int n;
 cin>>n;
 long long fact=1;
 int M=47;
 for (int i = 2; i <=n; i++)
 {
     fact = (fact * i)%M;
 }
 cout<<fact;
 
 //WHY M=10^9+7 is choosen in cp as M value
 //1. 10^9+7 is very close to int max , it means it can be stored in int data type.
 //2. multiplicative inverse(MMI) because M=10^9+7 is prime no.
 return 0;
}