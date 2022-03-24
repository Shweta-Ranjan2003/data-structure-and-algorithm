#include <iostream>
using namespace std;
const int M = 1e9+7;
const int N = 1e5+10;
long long fact[N];
/*
In first meathod as we observe the time complexity was high so we use pre computation techinque
in which we store all the number's factorial in an array and then we display the factorial as per the command.
*/
int main()
{ 
 //Given test cases T and in each test case a number N. Print its factorial where M=10^9+7.
 //Constraints
 // 1<=T<=10^5
 // 1<=N<=10^5
/*
 int t;
 cin>>t;
 while (t--)
 {
     int n;
     cin>>n;
     long long fact =1;
     for (int i = 0; i <=n; i++)
     {
         fact = (fact*i)%M;
     }
     cout<<fact<<endl;
 }
     
 //O(T*N) = 10^10   old time complexity
 */
fact[0]=fact[1]=1;
for (int i = 2; i <N; i++){
    fact[i]=fact[i-1]*i;
}
int t;
cin>>t;
while (t--)
{
    int n;
    cin>>n;
    cout<<fact[n]<<endl;
}
//I(N)+O(T)=10^5=10^5
 return 0;
}