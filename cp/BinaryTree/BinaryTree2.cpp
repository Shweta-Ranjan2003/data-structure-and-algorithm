#include <iostream>
#include <queue>
using namespace std;
/*
Binary Tree Traversal:- Process of visiting each node in the tree exactly once in some order.
1. Breadth-first:-Level order traversal (F,D,J,B,E,G,K,A,C,I,H)
2. Depth first:- First complete the family of which ever child is visited then come to next child.
<root><left><right> - Preorder traversal
<left><root><right> - Inorder traversal
<left><right><root> - Postorder traversal
                 F
              D       J
            B   E   G    K
          A  C       I
                    H
Preorder(DLR- data left right)
F,D,B,A,C,E,J,G,I,H,K
Inorder(LDR)
A,B,C,D,E,F,G,H,I,J,K
Postorder(LRD)
A,C,B,E,D,H,I,G,K,J,F
*/
struct Node
{
    char data;
    Node *left;
    Node *right;
};
Node* GetNewNode(char data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* Insert(Node* root , char data){
    if (root==NULL)
    {
        root = GetNewNode(data);
    }
    else if (data<= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
        return root;
}
//Breadth first
void LevelOrder(Node *root){
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    //while there is at least one discovered node
    while (!Q.empty())
    {
        Node* current = Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop(); //removing element at front
    }
    //Time complexity - O(N)
    //Space complexity - O(1)- best , O(N)-worst/avg
}
//Depth first
//Time complexity: O(n)
//Space complexity: O(h) 
//                 worst:O(N) , Best/avg: O(logn)
void Preorder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root){
    if(root==NULL)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Postorder(Node* root){
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
//Inorder Successor in a BST
//Case1: Node has right subtee - go deep to leftmost node in right subtree or Find min in right Subtee
//Case2: No right Subree - go to the nearest ancestor for which given node would be in left subree.
Node* Find(Node* root , int data){
    if (root==NULL) return root;
     else if(root->data==data) return root;
     else if(data<=root->data) return Find(root->left,data);
     else return Find(root->right,data);
    }
Node* FindMin(Node* root){
    if(root==NULL) return NULL;
    while(root->left!=NULL) root = root->left; 
    return root;
}
Node* GetSuccessor(Node * root , int data){
    //Search the node - O(h)
    Node* current = Find(root,data);
    if(current ==NULL) return NULL;
    //Case 1: Node has right subtree
    if(current->right!=NULL){
        return FindMin(current->right);
    }
    //Case2: No right subtree
    else {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor!= current){
            if (current->data<ancestor->data)
            {
                successor = ancestor; //so far this is the deapest node for which current node is in left
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
    }
}
int main()
{ 
Node* root = NULL;
root = Insert(root,'F');
root = Insert(root,'D');
root = Insert(root,'J');
root = Insert(root,'B');
root = Insert(root,'E');
root = Insert(root,'G');
root = Insert(root,'K');
root = Insert(root,'A');
root = Insert(root,'C');
root = Insert(root,'I');
root = Insert(root,'H');

 LevelOrder(root);
    cout<<endl;
 Preorder(root);
    cout<<endl;
 Inorder(root);
    cout<<endl;
 Postorder(root);
    cout<<endl;
 return 0;
}