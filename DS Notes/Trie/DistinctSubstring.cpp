#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Number of distinct substrings in a string
struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 
int countDistinctSubstrings(string &s)
{
    Node* root = new Node(); 
    int cnt = 0; 
    int n = s.size(); 
    for(int i = 0;i<n;i++)
    {
        string curr="";
        Node* node = root; 
        for(int j = i;j<n;j++) {
            if(!node->containsKey(s[j])) {
                node->put(s[j], new Node()); 
                cnt++; 
                //For printing all distinct substring
                curr+=s[j];
                cout<<curr<<endl;
            }
            node = node->get(s[j]); 
        }
    }
    return cnt+1; //+1 for empty string
}
int main()
{ 
 string inp;
 cin>>inp;
 cout<<countDistinctSubstrings(inp);
 return 0;
}