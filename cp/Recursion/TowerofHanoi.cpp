#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Direct formula 2^n -1;
int cnt(int n){
    if(n==0)return 0;
    return 2*cnt(n-1)+1;
}
void toh(int n,char src,char help,char dest){
  if(n==0)return;
  toh(n-1,src,dest,help);
  cout<<" Moving "<<n<<" from "<<src<<" to "<<dest<<endl;
  toh(n-1,help,src,dest);
}
int main()
{ 
 toh(3,'A','B','C');
 return 0;
}