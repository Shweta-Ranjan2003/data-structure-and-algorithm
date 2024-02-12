#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Letter Combinations of a Phone Number - LC
Given keypad of phone 
0-" "
2-"ABC"
3-"DEF"
4-"GHI"
5-"JKL"
6-"MNO"
7-"PQRS"
8-"TUV"
9-"WXYZ"

Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
that the number could represent. Return the answer in any order.
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

/*
Hw- Print permutations of a given string
*/

void solve(int index , string digits,string map[],string temp , vector<string>&ans){
    if(index>=digits.size()){
        ans.push_back(temp);
        return;
    }

    int number=digits[index]-'0';
    string value=map[number];

    for(int i=0;i<value.size();i++){
        temp.push_back(value[i]);
        solve(index+1,digits,map,temp,ans);
        temp.pop_back();
    }
}
int main()
{ 
        string digits;
        cin>>digits;
        vector<string>ans;
        if(digits.length()==0) return 0;
        string temp;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,map,temp,ans);
        for(auto it:ans)cout<<it<<" ";
 return 0;
}