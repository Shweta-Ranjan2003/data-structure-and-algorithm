#include <iostream>
#include <string>
#include <cwctype>
using namespace std;
 bool isPalindrome(string s) {
      if(s.length() <= 1) return true;
        int i = 0, j = s.length()-1;
        while(i < j){
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if(i < j && tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
 
int main()
{ 
 string check = "race34 a &ar";
 bool result = isPalindrome(check);
 cout<<result;
 return 0;
}