#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node{
int val;
Node* left;
Node* right;
};

int dfsHeight(Node* root){
if(root==NULL)return 0;
int left=dfsHeight(root->left);
if(left==-1)return -1;
int right=dfsHeight(root->right);
if(right==-1)return -1;

if(abs(left-right)>1)return -1;
return max(left,right)+1;
}
bool checkBalancedBT(Node* root){
//Balanced BT-> for every node , height(left)-height(right)<=1
/* Naive solution

if(node==NULL)return true;

int left=height(node->left);
int right=height(node->right);
if(abs(left-right)>1)return false;

bool left=checkBalancedBT(node->left);
bool right=checkBalancedBT(node->right);
if(!left or !right) return false;

return true;
*/
return dfsHeight(root)!=-1;
// tc-O(n) , sc-O(n)
}


int HeightBT(Node* root,int& maxi){
    if(root==NULL) return 0;
    int left=HeightBT(root->left,maxi);
    int right=HeightBT(root->right,maxi);
    maxi=max(maxi,left+right);
    return max(left,right)+1;
}
int DiameterofBT(Node* root){
//Longest path between any 2 nodes and it may or may not pass from root
int maxi=0;
int diameter=HeightBT(root,maxi);
return max(maxi,diameter);

//tc - O(n) , sc - O(n)
}

int HeightPath(Node* root,int& maxi){
    if(root==NULL)return 0;

    //max with 0 because we will ignore negative path sum
    int left=max(0,HeightPath(root->left,maxi));
    int right=max(0,HeightPath(root->right,maxi));
    maxi=max(maxi,left+right+root->val);

    return root->val+max(left,right);
    //because if you go one node up then you wont conside whole lower tree you will take max of lower left or right tree.
}
int maxPathSum(Node* root){
//return maximum path sum - path is going from one node to another may or may not pass from root
int maxi=INT_MIN;
int curr=HeightPath(root,maxi);
return maxi;
}
int main()
{ 
 
 return 0;
}