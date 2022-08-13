#include <iostream>
using namespace std;
/*
Function for cheacking IsBinarySearchTree or not
and
Delete a node from BST : Case 1: No Child
Case 2: one child
Case 3: 2 children (Find min in right subtree then copy the value in targetted node then Delete duplicate from right subtree)
             OR (find max in left then copy the value in targetted node then Delete duplicate from left subtree.)
*/
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* Insert(Node* root , int data){
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
Node* FindMin(Node* root){
    if (root==NULL)
    {
        cout<<"Error: tree is empty"<<endl;
        return root;
    }
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
Node* Delete(Node* root, int data){
  if(root==NULL)return root;
  else if(data<root->data) root->left = Delete(root->left,data);
  else if(data>root->data) root->right = Delete (root->right,data);
  else{
    //Case1: NO child
    if (root->left==NULL&&root->right==NULL)
    {
        delete root;
        root=NULL;
    }
    //Case2: One child
    else if (root->left==NULL)
    {
        Node* temp = root;
        root = root->right;
        delete temp;
    }
    else if (root->right==NULL)
    {
        Node* temp = root;
        root = root->left;
        delete temp;
    }
    //Case3: 2 children
    else{
        Node* temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right,temp->data);
    }
    }
    return root;  
}
// Meathod 2   TC:O(n)
bool IsBinarySearchTreeUtility(Node* root , int minValue , int maxValue){
    if(root==NULL) return true;
    if(root->data>minValue && root->data<maxValue
    && IsBinarySearchTreeUtility(root->left,minValue,root->data)
    && IsBinarySearchTreeUtility(root->right, root->data , maxValue))
    return true;
    else
    return false;
}
bool IsBst(Node* root){
    return IsBinarySearchTreeUtility(root,INT_MIN,INT_MAX);
}
//meathod 3 : We can print tree in inorder traversal and then check if its sorted(return true) or not(return false).
int main()
{ 
    Node* root = NULL;
root = Insert(root,7);
root = Insert(root,4);
root = Insert(root,9);
root = Insert(root,1);
root = Insert(root,6);
root = Insert(root,8);
int a = IsBst(root);
cout<<a;
Delete(root,9);
 
 return 0;
}
//Meathod 1
//We could also use Find MIN and Find Max function instead of issubtreelesser or greater.
// bool IsSubtreeLesser(Node* root , int value){
//     if(root==NULL) return true;
//     if(root->data<=value && IsSubtreeLesser(root->left,value)
//     &&IsSubtreeLesser(root->right,value)) return true;
//     else return false;
// }
// bool IsSubtreeGreater(Node* root , int value){
//     if(root==NULL) return true;
//     if(root->data>value && IsSubtreeGreater(root->left,value)
//     &&IsSubtreeGreater(root->right,value)) return true;
//     else return false;
// }
// bool IsBST(Node* root){
//     if(root==NULL) return true;
//     if(IsSubtreeLesser(root->left,root->data)
//     &&IsSubtreeGreater(root->right,root->data)
//     &&IsBST(root->left)
//     &&IsBST(root->right)) return true;
//     else
//      return false;
// }
//Above code is very expensive in terms of space and time complexity 