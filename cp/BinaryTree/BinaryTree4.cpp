#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
};
vector<int> iterativePreorder(Node* root){
//Stack - Whatever you encounter put it into stack from right to left fashion
//root left right
vector<int>preorder;
if(root==NULL)return preorder;
stack<Node*> st;
st.push(root);
while(!st.empty()){
    root=st.top();
    preorder.push_back(root->val);
    st.pop();
    if(root->right)st.push(root->right);
    if(root->left)st.push(root->left);
}
return preorder;
//tc/sc - O(n) / O(n)
}

vector<int> iterativeInorder(Node* root){
// left root right
stack<Node*>st;
vector<int>inorder;
Node* node=root;
while(true){
    if(node!=NULL){
       st.push(node);
       node=node->left;
    }
    else{
        if(st.empty()==true)break;
    node=st.top();
    st.pop();
    inorder.push_back(node->val);
    node=node->right;
}
return inorder;
// tc/sc - O(n)/O(n)
}

vector<int> iterativePostorder(Node* root){
//Using 2-stack put the node in st1 then pop and put it in st2 and push its left and right in st1
// left right root
stack<Node*>st1,st2;
vector<int>postorder;
st1.push(root);
while(!st1.empty()){
Node* node=st1.top();
st1.pop();
st2.push(node);
if(node->left)st1.push(node->left);
if(node->right)st1.push(node->right);
}
while(!st2.empty()){
    postorder.push_back(st2.top()->val);
    st2.pop();
}
return postorder;
// tc/sc - O(n)/O(2n)
}

vector<int> iterativePostorder2(Node* root){
//using 1 stack

stack<Node*>st;
Node* curr=root;
vector<int>postorder;

while(curr!=NULL or !st.empty()){
    if(curr!=NULL){
        st.push(curr);
        curr=curr->left;
    }
    else{
        Node* temp=st.top()->right;
        if(temp==NULL){
            temp=st.top();
            st.pop();
            postorder.push_back(temp->val);
            while(!st.empty() and temp==st.top()->right){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->val);
            }
        }
        else{
            curr=temp;
        }
    }
}
return preorder;
}


vector<vector<int>> allinOne(node *root)
{
//preorder - when came to that node for 1 time then go left
//inorder - when came to that node 2nd time then go right
//postorder - when came to that node for 3rd time then pop

    vector<vector<int>> ans;
    stack<pair<node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return ans;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);

    return ans;
    //tc - O(3n) sc-(4n)
}
int main()
{ 
 
 return 0;
}