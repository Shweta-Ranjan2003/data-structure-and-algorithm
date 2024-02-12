#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Print all Subset of a given string recursively

Hw - Subset sum
*/
void subset(int i,string& str,string& ans){
    if(i>=str.size()){
        cout<<ans<<endl;
        return;
    }

    //pick
    ans+=str[i];
    subset(i+1,str,ans);
    ans.pop_back();

    //not pick
    subset(i+1,str,ans);

    return;
}
int main()
{ 
 string str="abc";
 string ans="";
 subset(0,str,ans);
 return 0;
}