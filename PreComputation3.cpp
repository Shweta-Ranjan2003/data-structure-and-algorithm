#include <iostream>
using namespace std;
const int N = 1e5+10;
int hsh[N][26];
/*
Luffy with his crew is on the way to Dressrosa, where he will be fighting one of the warlords of the sea Doflamingo. But now
he is getting bored and wants do a fun activity He is very much obsessed with palindromes. Given a string S of lower case
English alphabet of length N and two Integers L and R he wants to know whether all the letters of the substring from index L
to R (L and R included) can be rearranged to form a palindrome or not. He wants to know this for Q values of L and R and
needs your help in finding the answer.
Palindrome is a string of characters which when reversed reads same as the original String.
CONSTRAINTS:
 1<= t <= 10
1 <= N, Q <= 100000
1<=L<=R<=N
'a'<= S[i] <= 'z' for 1<=i<=N
Input:- t for test cases.
N for length of string and Q for no. of queries
next line is for sting the string S
Output:- 
yes or no
*/
int main()
{ 
    /*
 int t;
cin >> t;
while(t--){
    int n, q;
    cin >> n >> q;
    string s;
     cin >> s;
     while(q--){
   int l, r;
   cin >> l >> r;
   int hsh[26];
   for (int i = 0; i < 26; ++i){
       hsh[i] = 0;
   }
    l--;r--;
    for (int i = l; i <= r; i++)
    {
       hsh[s[i]-'a']++; 
    }
    int oddct=0;
    for (int i = 0; i < 26; i++)
    {
        if (hsh[i]%2 != 0) 
        {
            oddct++;
        }
    }
        if (oddct>1) cout<<"no ";
        else cout<<"yes ";
    }
    //O(t*(n + q*(26+n+26))) = O(t*q*n) = 10*10^5*10^5 */
 int t;
cin >> t;
while(t--){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            hsh[i][j]=0;
        }
        
    }
    
    int n, q;
    cin >> n >> q;
    string s;
     cin >> s;
     for (int i = 0; i < n; i++)
     {
        hsh[i+1][s[i]-'a']++; 
     }
     for (int i = 0; i < 26; i++)
     {
         for (int j = 1; j <= n; j++)
         {
             hsh[j][i]+=hsh[j-1][i];
         }
         
     }
     
     while(q--){
   int l, r;
   cin >> l >> r;
    int oddct=0;
    for (int i = 0; i < 26; i++)
    {
        int charct = hsh[r][i]-hsh[l-1][i];
        if (charct %2 !=0)
        {
            oddct++;
        }
    }
        if (oddct>1) cout<<"no ";
        else cout<<"yes ";
     }
}
        
      //O(t*(n+n*26+q*26))
      //O(t*n * 26) = 10*10^5*26  
    
           
 return 0;
}