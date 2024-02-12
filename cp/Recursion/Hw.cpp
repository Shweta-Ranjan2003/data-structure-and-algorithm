#include <iostream>
#include <vector>
using namespace std;
/*
Given floor of N*4 , and given tile of size 1*4 
how many ways you can design the floor , tile can be fixed vertically or horizontally

f(n)=f(n-1)+f(n-4)
if tile putted vertically then length left n-1 and if horizontally then n-4 lenght left
*/

/*
Binary string of length n , with no consecutive ones
if(n==3)
000
010
100
001
101
*/

//Binary - (It also makes pattern of fibonacci in answer because if we fix 0 then rest will make combination of n-1 
//          if we fix 1 then we have no other option other than to take 0 next but for n-2 we can make combination after 10)
int ways(int n,int can,vector<int>&ds){
    if(n<=0){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return 1;
    }
    
    int ans=0;
    //pick
    if(can==1){
        ds.push_back(1);
     ans+=ways(n-1,0,ds);
     ds.pop_back();
    }
    ds.push_back(0);
    ans+=ways(n-1,1,ds);
    ds.pop_back();

    return ans;
}

int main()
{ 
  vector<int>ds;
 cout<<ways(3,1,ds);
 return 0;
}