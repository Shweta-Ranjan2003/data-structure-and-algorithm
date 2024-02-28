#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntPrefix=0;
    int cntEndwith=0;

    bool contains(char &ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char &ch){
        return links[ch-'a'];
    }
    void put(char&ch , Node*node){
        links[ch-'a']=node;
    }
    void increaseEnd(){
        cntEndwith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndwith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndwith;
    }
    int getPrefix(){
        return cntPrefix;
    }
}

class trie{
    public:
    Node*root;
    trie(){
        root=new node();
    }
    void insert(string&word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->contains(word[i])==false){
                node->put(word[i],new node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string& word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->contains(word[i])==false)return 0;
            node=node->get(word[i]);
        }
        return node->getEnd();
    }
    int countWordsStartingWith(string& word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->contains(word[i])==false)return 0;
            node=node->get(word[i]);
        }
        return node->getPrefix();
    }
    void erase(string&word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->contains(word[i])==false)return;
            node=node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
        return;
    }
}
int main()
{ 
 
 return 0;
}