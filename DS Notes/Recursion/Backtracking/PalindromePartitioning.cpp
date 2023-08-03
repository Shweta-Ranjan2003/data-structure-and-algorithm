#include <iostream>
using namespace std;
/*
You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.
Input: s = “aabc”
Output: [ ["a","a","b","c"], ["aa","b","c"] ]	
Input: s = “aabb”
Output: [ [“a”,”a”,”b”,”b”], [“aa”,”bb”], [“a”,”a”,”bb”], [“aa”,”b”,”b”] ] 
*/

/*
bool isPalindrome(string s, int start , int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void recur(int ind , string s , vector<string>&ds , vector<vector<string>>& ans){
  if(ind==s.size()){
      ans.push_back(ds);
      return;
  }
  for(int i=ind;i<s.size();i++){
      if(isPalindrome(s,ind,i)){
          ds.push_back(s.substr(ind,i-ind+1));
          recur(i+1,s,ds,ans);
          ds.pop_back();
      }
  }
}
*/
int main()
{ 
 
 return 0;
}