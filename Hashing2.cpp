//PRE FIX SUM IN 1D AND 2D ARRAY
#include <iostream>
using namespace std;
//const int N = 1e5+10;
//int a[N];
//int pf[N];
const int N = 1e3+10;
int ar[N][N];
long long pf[N][N];
int main(){
/*
Given array a of N integers. Given Q queries and in each query L and R print sum of
array elements from index L to R(L,R included)
Constraints
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L, R<=N
*/
                                                          //PRE FIX SUM OF 1D ARRAY
 /*
 int n;
 cin>>n;
 for (int i = 1; i <=n; i++)
 {
     cin>>a[i];
 }
 int q;
 cin>>q;
 while (q--)
 {
     int l,r;
     cin>>l>>r;
     long long sum=0;
     for(int i =l;i<=r;i++){
         sum+= a[i];
     }
     cout<<sum<<endl;
 }
 //O(N) + O(q*n) = 10^10 */
 /*
 int n;
 cin>>n;
 for (int i = 1; i <=n; i++)
 {
     cin>>a[i];
     pf[i]=pf[i-1]+a[i];
 }
 int q;
 cin>>q;
 while (q--)
 {
     int l,r;
     cin>>l>>r;
     cout<<pf[r]-pf[l-1]<<endl;
 }
//O(n) +O(q) = 10^5;
*/
/*
Given 2d array a of N*N integers. Given Q queries and in each query given a,b,c and d
print sum of square represented by (a,b) as top left point and (c,d) as bottom right point.
Constraints
1<=N<=10^3
1<=a[i][j]<=10^9
1<=Q<=10^6
1<=a,b,c,d<=N
*/
                                                //PRE FIX SUM OF 2D ARRAY
/*
int n;
cin>>n;
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        cin>> ar[i][j];
    }
}
 int q;
 cin>>q;
 while(q--){
     int a,b,c,d;
     cin>>a>>b>>c>>d;
     long long sum =0;
     for (int i = a; i <=c; i++)
     {
         for (int j = b; j <=d; j++)
         {
             sum += ar[i][j];
         }
         
     }
     cout<<sum<<endl;
 }   
//O(n^2) + O(q*n^2) = 10^11
*/
int n;
cin>>n;
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        cin>> ar[i][j];
        pf[i][j] = ar[i][j]+ pf[i-1][j] + pf[i][j-1]-pf[i-1][j-1];
    }
}
 int q;
 cin>>q;
 while(q--){
     int a,b,c,d;
     cin>>a>>b>>c>>d;
     
     cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1]<<endl;
 }   
 //O(N^2) + O(q) = 10^6
 return 0;
}