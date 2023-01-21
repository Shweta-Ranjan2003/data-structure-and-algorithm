#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
// 1. Valid paranthesis
 bool isValid(string s) {
        stack<char> a;
        for(int i = 0; i< s.length() ; i++){
            if(a.empty()){
                a.push(s[i]);
            }
            else if((s[i]==')' && a.top()=='(' ) || (s[i]=='}' && a.top()=='{' ) || (s[i]==']' && a.top()=='[' ) ){
                 a.pop();}
            else a.push(s[i]);
            }
        if (a.empty()){
            return true;
        }
        return false;
    }
int main()
{ 
  string para = "{[]}()";
  bool result = isValid(para);
  cout<<result<<endl;
 return 0;
}
*/
/*
// 2.  Minimum Insertions to Balance a Parentheses String
// for closing ( we need 2 )) . Input: s = "))())(" Output: 3
int minInsertions(string s) {
        int invalidcount = 0;
        int stock = 0;
        for(int i = 0; i<s.length() ; i++){
            char c = s[i];
            if(c=='('){
                stock++;
            }
            else{
                if(i+1 == s.length() || s[i+1]!=')'){
                    invalidcount++;
                }
                else{ i++ ;}
                if(stock == 0){
                    invalidcount++;
                }
                else{
                    stock--;
                }
            }
        }
        return (invalidcount + 2*stock);
    }
    int main(){
        string parantheses;
        cin>>parantheses;
        int insertion = minInsertions(parantheses);
        cout<<insertion;
    }
*/
