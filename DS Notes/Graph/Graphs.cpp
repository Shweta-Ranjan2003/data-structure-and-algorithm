#include <iostream>
#include <vector>
#include <queue>
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

Degrees of Graph -> Total degrees= 2*E
Indegree - no of incoming edges
Outdegree - no of outgoing edges

Lets say if there is a 10 node graph but they are not connected ,they are in 4 different component
1-2  5-6 7-8  10
4-3        9
then for traversing the graph we can make a visited array of size 10
and start from 1 and mark the visited nodes
1. 1-T , 2-T , 3-T , 4-T
Then for traversing 5 you have to travel that component
2. 5-T 6-T
3. 7-T 8-T 9-T
4. 10-T
for(int i=1;i<=10;i++){
    if(!vis[i]){
        traverse(i);
        array[i]=True;
    }
}
*/

//Traversal
/*
Breadth first traversal - Level wise (0-n)
        1
    2       6
 3     4  7    8
         5
Starting node 1 - 1 2 6 3 4 7 8 5
Starting node 6 - 6(0) 1 7 8(1) 2 5(2) 3 4(3) level

        1
    2       6
 3     4  7    9
      5----8
Adjacency list
1 -> 2,6
2-> 1,3,4
3-> 2
4-> 2,5
5-> 4,8
6-> 1,7,9
7-> 6,8
8-> 5,7
9-> 6

use queue and visited array of  size 10 and mark visited node
queue - 1 2 5 3 4 7 9 5 8 = bfs 
*/
vector<int> bfs(int V , vector<int> adj[]){
   vector < int > bfs;
      vector < int > vis(V, 0);
      queue < int > q;
      q.push(0);
      vis[0] = 1;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it: adj[node]) {
          if (!vis[it]) {
            q.push(it);
            vis[it] = 1;
          }
        }
      }

      return bfs;
}

/*
DFS - depth first search
       1
    2     3---4
          |   |
  5   6   7---8

  dfs - 1 2 5 6 3 7 8 4
 starting node = 3 -> 3 4 8 7 1 2 5 6
 use recursion to traverse and come back
 adjacency list 
 1-> 2,3
 2-> 1,5,6
 3-> 1,4,7
 4-> 3,8
 5-> 2
 6-> 2
 7-> 3,8
 8-> 4,7

 create a visited node of size 0-8
 dfs(node){
    vis[node]=1;
    list.add(node)
    for(auto it:adj[node]){
        if(!vis[it])
        dfs(it)
    }
 }
 1,2,5,6,3,7,8,4
*/

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); //remove this line in case of directed graph
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}



int main() 
{
/*
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);
    // 0 2 4 1 3
*/
 vector < int > adj[5];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 4);

  
  vector < int > ans = bfs(5, adj);
  printAns(ans);
  cout << endl;
// 0 1 2 3 4
    return 0;
}