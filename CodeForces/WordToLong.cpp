#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Sometimes some words like "localization" or "internationalization" 
are so long that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 
characters. All too long words should be replaced with a special abbreviation.
"localization" will be spelt as "l10n", and "internationalization» will be 
spelt as "i18n"
*/
int main()
{ 
 int n;
 cin>>n;
 vector<string>ans(n);
 for(int i=0;i<n;i++){
    string current;
    cin>>current;
    if(current.size()>10){
       int len=current.size();
       int remaining=len-2;
       string temp="";
       temp+=current[0];
       temp+=to_string(remaining);
       temp+=current[len-1];
       ans.push_back(temp);
    }
    else ans.push_back(current);
 }
 for(auto it:ans){
     cout<<it<<endl;
 }
 return 0;
}