#include <iostream>
using namespace std;
/*
Graph:- A graph G is an ordered pair of a set V of vertices and a set E of edges.
G=(V,E)  |V| = number of vertices , |E|=number of edges.       
ordered pair: (a,b)!=(b,a) if a!=b
unordered pair: {a,b}
a directed graph is called Digraph(edges are unidirectional or ordered pair) and an undirected graph(edges are bidirectional or unordered pair).

Weighted vs unweighted graph:-
weighted graph:-  a graph in which each branch is given a numerical weight.
unweighted graph:- a weighted graph with all edges having weight = 1unit.

Properties of Graph
1. Self-loop
2. Multiedge

Number of edges:- if |v|=n then, 0<=|E|<=n(n-1) , if directed
                           then, 0<=|E|<=n(n-1)/2 , if undirected
                  Assuming no self-Loop or multiedge    

Walk= a sequence of vertices where each adjacent pair is connected by an edge.
Path(simple) = a walk in which no vertices(and thus no edges) are repeated.     
Trail= a walk in which no edges are repeated.
closed walk = Starts and ends at same vertex
Strongly connected Graph= if there is a path from any vertex to any other vertex
simple cycle = no repetition other than start and end
Acyclic Graph = a graph with no cycle
*/
/*
Edge list:- We use two list one to store vertices and other to store the edges
            In vertices we store name of the node and in edges we store references of the two end point of the edge and also the weight of that age.
Finding adjacent nodes :- O(|E|)  , where O(|E|) can be v^2
Check if given nodes are connected:- O(|E|)

Adjacency matrix:- eg:- if we have 8 vertices then we define an 2d array of 8*8 and store 1(true) where i and j of Aij have connections and 0 otherwise.
 Same for weighted graph instead of 0 and 1 we can store infine and weight of that edge.(undirected graph)
finding adjacent nodes:- O(v)+O(v) = O(v)
finding if two nodes are connected or not:- O(1)+O(v) (O(v) because we will have to find indices or given vertice, the scanning of vertice list all the time to figure out the indices can be avoided,
 we can create hash table with names and indices as key value pair and then the time cost of finding index from name would also be O(1).
But space used in adjacenty matrix = O(v^2) , if edges is very less than we are wasting lots of memory for storing 0 !

Adjacency list:- instead of using a 2d array of v*v , we can define a structure of pointer array[size= v] and then for each vertice index we can define a new array of size of total no. of edges to that vertice with index of that vertice
eg:- int *A[8];
A[0] = new int [3]     //0 {1,2,3} where 0 is index of vertice and 1,2,3 are index of vertice connected via edge to 0
A[7] = new int [4]     //7 {3,6,4,5}
But then adding a new node connection will be costly so why not use a linked list
struct Node*{ int data; int weight ; struct Node* next;};
Node* A[8]; for storing the head address of the list
Space Complexity = O(|E|)+(|V|)
|E|<<|V|*|V|  (most graph are sparse)
We can still do better with a binary tree....
*/
int main()
{ 
 
 return 0;
}