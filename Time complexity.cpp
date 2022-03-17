#include <iostream>
using namespace std;
/*
 O(N) + O(N) = O(N)
 O(K*N) and k<<N = O(N)
 O(2) + O(6) = O(1)
 Number of iteration in 1 sec = 10^7 - 10^8 on cp websites
 lets say 10^7 iteration takes 1 second then,
 10^8 = 10seconds
 10^9 = 100seconds
 10^10 = 1000seconds - approx 15 minutes.
*/
int main()
{ 
 int x=0; //1 iteration
 int n; //1 more iteration
 cin>>n; //1 more
 //time complexity = O(3)
 //n<100000
 for(int i = 0; i<n;i++)
 {
     int l = x+i;
     l++;
 }
 //time complexity = O(3) + O(2*n)  because inside each iteration of loop there will be two more iteration
 //overall time complexity = O(n) because O(3) is negligible in front of O(2*n) and 2*n is of same order as n.
 for(int i = 0; i<n;i++)
 {
     for (int k = 0; k < n; k++)
     {
     int l = x+i;
     l++;
     }
}
// O(n^2) = O(n^2)  = n<10^5 , n^2<10^10 which will take approx 15min to run.
//m<10^5
int m;
cin>>m;
int ct=0;
while(m>0){
    m=m/2;
    ct++;
}
//iteration will occur till m gets 0 by getting divided by 2 in each iteration
// 2^a=M
//log(2^a) = log(M)  //log base 2
// a log 2 = log (M)
// a = log (M)
// a is how many times we will divide M to make it 0
//it means iteration will happen log(M) times
//time complexity = O(3)+O(log(n)) = O(log(n))
//eg:- log(10^5) = 5 log(10) = 15 iteration
//log(10^18) = 18 log(10) = 18*3 = 54 iteration

int j;
cin>>j;
int count = 0;
for (int k = 0; k <= j; k++)
{
    for (int y = 0; y < k; y++)
    {
        count++;
    }
}
//for k=0 , y=0 iteration     
//for k=1 , y=1 iteration     
//for k=2 , y=2 iteration     
//for k=j , y=j iteration   
//total itertion of inner loop = 0+1+2....+j = j(j+1)/2
//O(j^2/2 + j/2)
//O(j^2/2) + O(j/2)     //ignore j/2 because its negligible in front of j^2/2
//j=10^5 , j^2 = 10^10
// TIME COMPLEXITY = O(j^2)



                                                       //SPACE COMPLEXITY
int a;
int b =10;  
//space complexity = O(1)

int ar=100;
int arr[ar];
//space complexity = O(n)

int arr[ar][ar];
//space complexity = O(n^2)

//O(1) + O(n) + O(n^2) = O(n^2)

 return 0;
}