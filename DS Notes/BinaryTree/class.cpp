#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *left , *right;
};
node *create(){
    int x;
    cout<<"Enter '-1' for no node.";
    cin>>x;
    if(x==-1){
        return 0;
    }
    else{
        node *newnode;
        newnode = new node;
        newnode->data= x;
        newnode->left = NULL;
        newnode->right = NULL;
        cout<<"Enter left child of "<<x<<" : ";
        newnode->left = create();
        cout<<endl;
        cout<<"Enter right child of "<<x<<" : ";
        cout<<endl;
        newnode->right = create();
        return newnode;
    }
}
//Traverse preorder
void traversePreOrder(node* temp){
    if(temp!=NULL){
        cout<<" "<<temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}
void traversePostOrder(node* temp){
    if(temp!=NULL){
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
        cout<<" "<<temp->data;
    }
}
void traverseInOrder(node* temp){
    if(temp!=NULL){
        traversePreOrder(temp->left);
        cout<<" "<<temp->data;
        traversePreOrder(temp->right);
    }
}
int main()
{ 
 node *root;
 root = NULL;
 root = create();
 cout<<"Inorder : ";
 traverseInOrder(root);
 cout<<"Preorder : ";
 traversePreOrder(root);
 cout<<"postorder : ";
 traversePostOrder(root);
 return 0;
}