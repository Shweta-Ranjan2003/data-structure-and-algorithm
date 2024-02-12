#include<iostream>
#include<unordered_map>
#include <bits/stdc++.h>
using namespace std;
class TrieNode{
public:
    bool is_Terminal;
    vector<TrieNode*> children;
    TrieNode(){
        is_Terminal=false;
        children=vector<TrieNode*>(26, NULL);
    }   
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
               cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_Terminal=true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]=='#') return;
        if(root->children[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->children[board[x][y]-'a']; 
            if(root->is_Terminal) result.insert(word);
            char c=board[x][y];
            board[x][y]='#';
            dfs(board, x+1, y, root, word, result);
            dfs(board, x-1, y, root, word, result);
            dfs(board, x, y+1, root, word, result);
            dfs(board, x, y-1, root, word, result);
            board[x][y]=c;        
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root=trie->getRoot();
        set<string> result_set;
        for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                dfs(board, x, y, root, "", result_set);
        
        vector<string> result;
        for(auto it:result_set) result.push_back(it);
        return result;        
    }
    
};
int main(){
		vector<string>words{"Tea","Teabreak","Snake","Snacks","Snakes","Songs","Swe"};
        Trie t;
        for(auto it:words){
            t.insert(it);
        }
        vector<vector<char>>board{"GEEKS","FOR","QUIZ","GO"};
        int r=board.size();
        vector<string>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<board[i].size();j++){
                if(t.searchfirst(char[i][j])==true){
                    vector<vector<bool>>vis(r,vector<bool>(r,false));
                    vector<vector<bool>>pathvis(r,vector<bool>(r,false));
                    dfs(i,j,board,vis,pathvis,ans,temp);
                }
            }
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
		return 0;
}
