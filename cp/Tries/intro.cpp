#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Homework - Make a autocomplete feature where suggest(string prefix) we return suggestions

/*
Tries is a generic tree where there is no limit on no.
of children of a node.

eg of question - string searching,hashing,graph+trie,
maximum xor pair
*/

/*
1. String searching
words=["apple","app","batsman","new","news","ape"];
1.linear search for a word will take (n*words_length)
2.Hash map will take O(1)
3. Trie-
we will take a root then
                       root
                a        b        n
                p        a        e
            p      e     t        w
            l            m        s
            e            a      
                         n

Here we have to mark both e , second p and n and w and s as a terminal node
because there are words ending at these letters
and for every node we will have map where we will store char,node* key value pair
where we will have address of next node starting with respective letter
for eg if ape comes after apple then root will give address of a of apple
then p from apple then p will not have address of e so will we add new node with letter e

*/

class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}
};


class Trie{

	Node*root;
public:
	Trie(){
		root = new Node('\0');
	}

	//later
	void insert(string word){

		Node* temp = root;

		for(char ch : word){

			if(temp->m.count(ch)==0){
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}

		temp->isTerminal = true;

	}

	bool search(string word){

		Node*temp = root;

		for(char ch : word){

			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];


		}
		return temp->isTerminal;
	}
};


int main(){

		string input = "this is a suffix trie";
        Trie t;
        t.insert(input);
        cout<<t.search("this is a suffix trie")<<endl;
        cout<<t.search("this is a suffix tri")<<endl;


		return 0;
}