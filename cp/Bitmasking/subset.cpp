#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
/*
s="abc" , n=3   
2^3=8 0to7
000 0 =""  (0&0,1,2==0)
001 1 = "a" (1&(1<<0)!=0) a , (1&(1<<1)==0) , (1&(1<<2)==0)
010 2 = "b" (2&(1<<1)!=0) b , (2&(1<<0,2)==0) 
011 3 = "ab" (3&(1<<0)!=0) a , (3&(1<<1)!=0) b , (3&(1<<2)==0) 
100 4 = "c"  (4&(1<<0)==0)  , (4&(1<<1)==0) , (4&(1<<2)!=0) c
101 5 = "ac" (5&(1<<0)!=0) a , (5&(1<<1)==0) , (5&(1<<2)!=0) c 
110 6 = "bc" (6&(1<<0)==0)  , (6&(1<<1)!=0) b , (6&(1<<2)!=0) c
111 7 = "abc" (7&(1<<0)!=0) a , (7&(1<<1)!=0) b , (7&(1<<2)!=0) c
*/
void print(string s){
    int n=s.length();
    int size=(1<<n); //2^n
    for(int i=0;i<size;i++){
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0) cout<<s[j];
        }
        cout<<endl;
    }
}

/*
Leetcode Single number 2 - every number repeating 3 times except one tell that one
*/
int SingleNumber2(vector<int>&nums){
    string ans="";
    int no=0;
    int n=nums.size();
    for(int i=0;i<32;i++){
        int sum=0;
        for(int j=0;j<n;j++){
          if(nums[j]&1==1){
            sum++;
          }
          nums[j]=nums[j]>>1;
        }
        if(sum%3==1){
            ans="1"+ans;
        }
        else ans="0"+ans;
        no=no+(sum<<i);
    }
    cout<<ans<<endl;
    return no;
}

//SPOJ - Subsums
int main()
{ 
string s="abc";
//print(s);
vector<int>nums{5,7,5,5,2,2,2};
int no=SingleNumber2(nums);
cout<<no;
 return 0;
}