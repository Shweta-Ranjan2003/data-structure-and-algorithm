#include <iostream>
using namespace std;
/*
A collection of entities called nodes linked together to stimulate a heirarchy.
tree is a non-linear stucture, its a heirarichal structure the top most node is called root.
Some terms use in tree (root- top most node , children , parent , sibling(have same parent) , leaf(node that do not have any children node))
If we can go from A to B , A is ancestor of B and B is descendent of A
Tree -> recursive data structure , N nodes (N-1 edges).
Depth and height = Depth of x=length of path from root to x OR no. of edges in path from root to x
Height of x=  No. of edges in longest path from x to a leaf.
Height of tree = height of root node
*/
/*
Binary Tree -> A tree in which each node can have at most 2 children.
strict/proper binary tree -> each node can have either 2 or 0 children
complete binary tree -> all levels except possibly the last are completely filled and all nodes are
as left as possible.
perfect binary tree ->is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.
{Max no. of nodes at level i=2^i}
{Max no. of nodes in a binary tree with height h = 2^0+2^1+...+2^h = 2^(h+1)-1} if n is given then h=log2(n+1)-1
{Height of complete binary tree = [log2n]}
Balanced binary tree -> difference between height of left and right subtree for every node is not more than k(mostly 1) {diff=|height of left - height of right|}
Height of an empty tree = -1 and height of tree with 1 node = 0
struct Node{
    int data;
    Node* left;
    Node* right;
};
We can implement binary tree using: a) dynamically created nodes b)array(used for heap)
IN COMPLETE BINARY TREE Array for node at index i, 
left child index = 2i+1
right child index = 2i+2 
*/
/*
Binary Search Tree -> A binary tree in which for each node , value of all the nodes in left subtree is lesser or equal and value of all the nodes in right subtree is greater.
*/
int main()
{ 
 
 return 0;
}