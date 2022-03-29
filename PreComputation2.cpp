#include <iostream>
using namespace std;
const int N = 1e7+10;
long long int ar[N];
/*
Starting with a 1-indexed array of zeroes and a list of operations, for each operations add a value to each the array elements
between two given indices, inclusive. Once all operations have been performed , return the maximum value in the array.
Example
n=10;
queries = [1,5,3],[4,8,7],[6,9,1]]
queries are
a b k
1 5 3
4 8 7
6 9 1
add the value of k between a and b
[3,3,3,10,10,8,8,8,1,0] 
return max value = 10;
Constraints:-
3<=n<=10^7
1<=m<=2*10^5
1<=a<=b<=n
0<=k<=10^9
eg:-
1 2 3 4 5
0 0 0 0 0  (2 to 3 indexed 5)
0 5 0 -5 0  (ar[l]+=5; , ar[r+1]-=5;)
0 5 5 0 0   (pre fix sum of 1d array )
*/
 int main(){
     /*
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b, d;
        cin >> a >> b >> d;
        for (int i = a; i<= b; ++i){ 
             ar[i] += d;
        }
    }
    long long mx = -1;
    for(int i = 1; i <=n; ++i){
        if (mx < ar[i]){
             mx = ar[i];
         }
    }
    cout << mx << endl;
    // 0 (m * n + n) = 2*10^5 * 10 ^ 7 */
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b, d;
        cin >> a >> b >> d;
        ar[a] +=d;
        ar[b+1] -=d;
    }
    //Pre fix sum concept of 1D array concept.
    for (int i = 1; i <=n; i++)
    {
        ar[i] += ar[i-1];
    }
    
    long long mx = -1;
    for(int i = 1; i <=n; ++i){
        if (mx < ar[i]){
             mx = ar[i];
         }
    }
    cout << mx << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<ar[i]<<" ";
    }
    
//O(m+n+n) = 2*10^5 + 10^7 = 10^7
 return 0;
}