#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Generate Paranthesis - gfg

int ways(int left,int right,vector<char>&ds){
    if(left==0 && right==0){
        for(auto it:ds)cout<<it;
        cout<<endl;
        return 1;
    }
    
    int ans=0;
    if(left==right){
        ds.push_back('(');
        ans+=ways(left-1,right,ds);
        ds.pop_back();
    }
    else if(left<right){
       if(left>0){
        ds.push_back('(');
        ans+=ways(left-1,right,ds);
        ds.pop_back();
       }
       ds.push_back(')');
       ans+=ways(left,right-1,ds);
       ds.pop_back();
    }
    return ans;
}
int main()
{ 
  vector<char>ds;
 cout<<ways(3,3,ds);
 return 0;
}