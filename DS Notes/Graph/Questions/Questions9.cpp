#include <bits/stdc++.h>
using namespace std;
/*
133. Clone Graph
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
*/
 unordered_map<Node*,Node*>mp;
    void dfs(Node* node, Node* clone_node){
        for(auto it:node->neighbors){
           if(mp.find(it)==mp.end()){
               Node* clone=new Node(it->val);
               mp[it]=clone;
               clone_node->neighbors.push_back(clone);
               dfs(it,clone);
           }
           else{
               clone_node->neighbors.push_back(mp[it]);
           }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        mp.clear();
      Node* clone_node=new Node(node->val);
      mp[node]=clone_node;
      dfs(node,clone_node);
      return clone_node;
    }

/*
2101. Detonate the Maximum Bombs
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.
Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonat
*/
 typedef long long LL;
    void DFS(int u, unordered_set<int> & visited, unordered_map<int, vector<int>> &adj) {
        
        visited.insert(u);
        
        for(int &v : adj[u]) {
            if(visited.find(v) == visited.end()) { //Not visited
                DFS(v, visited, adj);
            }
        }

    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        unordered_set<int> visited;
        
        for(int i = 0; i<n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = max(result, count);
            visited.clear();
        }
        
        return result;
        
    }

    //Using bfs
     typedef long long LL;
    int BFS(int u, unordered_map<int, vector<int>> &adj) {
        unordered_set<int> visited;
        queue<int> que;
        que.push(u);
        visited.insert(u);

        while(!que.empty()) {
            
            int temp = que.front();
            que.pop();
            
            for(int &v : adj[temp]) {
                
                if(visited.find(v) == visited.end()) {
                    que.push(v);
                    visited.insert(v);
                }
                
            }
            
            
        }
        
        return visited.size();
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            int count = BFS(i, adj);
            result = max(result, count);
        }
        
        return result;
        
    }
int main()
{ 
 
 return 0;
}