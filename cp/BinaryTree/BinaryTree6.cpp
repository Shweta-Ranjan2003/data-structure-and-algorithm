#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *left;
	Node *right;
 
	Node(int d){
		data = d;
		left = right = NULL;
	}
};

Node* Insert(Node*root,int key){
	if(root==NULL){
		return new Node(key);
	}
	if(key<root->data){
		root->left = Insert(root->left,key);
	}
	else{
		root->right = Insert(root->right,key);
	}
	return root;
}


void printPaths(Node* root, vector<int>&path){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        for(auto it:path)cout<<it<<" ";
        cout<<root->data<<endl;
        return;
    }
    path.push_back(root->data);
    printPaths(root->left,path);
    printPaths(root->right,path);
    path.pop_back();
}
int main()
{ 
 Node* root = NULL;
root = Insert(root,15);
root = Insert(root,10);
root = Insert(root,20);
root = Insert(root,25);
root = Insert(root,8);
root = Insert(root,12);
vector<int>path;
printPaths(root,path);
 return 0;
}