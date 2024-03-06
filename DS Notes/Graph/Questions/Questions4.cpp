#include <bits/stdc++.h>
using namespace std;
/*
Make Palindrome
You are given a sequence of n positive integers: a=(a1​,a2​,…an​). You can do the operation below zero or more times. At least how many operations are needed to make A a palindrome?

Choose a pair (x,y) of positive integers, and replace every occurrence of x in a with y.

Here, we say a is a palindrome if and only if ai​=an+1−i​ holds for every (1≤i≤n).

Constraints:

1 <= n <= 2*10^5

1 <= ai <= 2*10^5

Example:

Input: n= 8 , a= [1, 5, 3, 2, 5, 2, 3, 1]
 
Output: 2
 
Explanation:
Initially, we have A=(1,5,3,2,5,2,3,1).
After replacing every occurrence of 3 in A with 2, we have A=(1,5,2,2,5,2,2,1).
After replacing every occurrence of 2 in A with 5, we have A=(1,5,5,5,5,5,5,1).
In this way, we can make A a palindrome in two operations, which is the minimum needed.
*/
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int>parent,sizee;
    DisjointSet(int n){
        parent.resize(n+1);
        sizee.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            sizee[i]=1;
        }
    }
    int FindUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=FindUPar(parent[node]);
    }
    int UnionBySize(int u,int v){
        int ulp_u=FindUPar(u);
        int ulp_v=FindUPar(v);
        if(ulp_u==ulp_v){
            return 0;
        }
        if(sizee[ulp_u]<sizee[ulp_v]){
            parent[ulp_u]=ulp_v;
            sizee[ulp_v]+=sizee[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            sizee[ulp_u]+=sizee[ulp_v];
        }
        return 1;
    }
};
int solve(int n, vector<int> a){
    DisjointSet ds(n);
    int ans=0;
    for(int i=0;i<n/2;i++){
        int j=n-i-1;
        ans+=ds.UnionBySize(a[i],a[j]);
    }
	return ans;
}
int main(){

}

/*
1579. Remove Max Number of Edges to Keep Graph Fully Traversable
Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between 
nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, 
the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob 
if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

Example 1:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. 
Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
*/

class DSU {
    private:
        vector<int> parent;
        vector<int> rank;
        int components;

    public : 
        
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            components = n;
            for(int i = 1; i<=n; i++) {
                parent[i] = i;
            }
        }
    
        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
        }
    
        bool isSingle() {
            return components == 1;
        }
};
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] > v2[0];
}
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(begin(edges), end(edges), sortcol);
        DSU Alice(n);
        DSU Bob(n);
        
        int addedEdge = 0;
        
        for (auto &edge: edges) { // For each edge -
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if(type == 3) {
                bool add = false;
                
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    add = true;
                }
                
                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    add = true;
                }
                
                if(add)
                    addedEdge++;
                
            } else if(type == 2) {
                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    addedEdge++;
                }
            } else {
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    addedEdge++;
                }
            }
        }
        
        
        if(Alice.isSingle() && Bob.isSingle()) {
            return edges.size() - addedEdge;
        }
        
        return -1;
    }
};