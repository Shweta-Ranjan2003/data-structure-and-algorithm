#include <iostream>
using namespace std;
const int N = 1e7+10;
int hashing[N];
/*
Given array a of N integers. Given Q queries and in each query given a number X,print
count of that number in array.
Constraints
1<=N<=10^5
1<=a[i]<=10^7
1<=Q<=10^5
*/
int main()
{ /*
 int n;
 cin>>n;
 int a[n];
 for (int i = 0; i < n; i++)
 {
     cin>>a[i];
 }
 int q;
 cin>>q;
 while (q--)
 {
     int x;
     cin>>x;
     int ct=0;
     for (int i = 0; i < n; i++)
     {
         if (a[i]==x)
         {
            ct++;
         }
         
     }
     cout<<ct<<endl;
 }
 //O(n)+O(q*n) = 10^5 + 10^5*10^5 = O(N^2) = 10^10
 */
 int n;
 cin>>n;
 int a[n];
 for (int i = 0; i < n; i++)
 {
     cin>>a[i];
     hashing[a[i]]++;
 }
 int q;
 cin>>q;
 while (q--)
 {
     int x;
     cin>>x;
     cout<<hashing[x]<<endl;
 }
 //O(N) + O(Q) = O(N) = 2*10^5
 
 return 0;
}