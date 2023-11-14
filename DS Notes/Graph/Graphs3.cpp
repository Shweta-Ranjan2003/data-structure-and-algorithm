#include <iostream>
using namespace std;
/*
Bipartite Graph:- If you can color the graph with 2 colors such that no adjacent nodes have same color.
Linear graph with no cycles are always bipartite
any graph with even cycle length is also bipartite
any graph with odd cycle length is never bipartite

     3
1  2   4  7  8
   6   5 

queue - 1 2 3 6 4 5
color - 0 1 0 1 1 0 -1 -1
node = 4 has a color 1 but adjacent 5 has same color so its not bipartite

//-------BFS--------
 bool check(int start, int V, vector<int>adj[], int color[]) {
        queue<int> q;
	    q.push(start); 
	    color[start] = 0; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        
	        for(auto it : adj[node]) {
	            // if the adjacent node is yet not colored
	            // you will give the opposite color of the node 
	            if(color[it] == -1) {
	                
	                color[it] = !color[node]; 
	                q.push(it); 
	            }
	            // is the adjacent guy having the same color 
	            // someone did color it on some other path 
	            else if(color[it] == color[node]) {
	                return false; 
	            }
	        }
	    }
	    return true; 
    }

	bool isBipartite(int V, vector<int>adj[]){
	    int color[V]; 
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    for(int i = 0;i<V;i++) {
	        // if not coloured
	        if(color[i] == -1) {
	            if(check(i, V, adj, color) == false) {
	                return false; 
	            }
	        }
	    }
	    return true; 
	}

//-------DFS--------
     3
1  2   4  7  8
   6   5 
dfs - (1,0) (2,1) (3,0) (4,1) (7,0) (8,1) (5,0) (6,1) now 6 got a adj node with same color
so not bipartite

bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) 
	                return false; 
	        }
	    }
	    return true; 
	}
*/


/*
Detect cycle in a directed graph using DFS
if its directed then on the same path , node has to be visited again
We will have two array visited and path visited because once we visit a node
and we didn't find cycle in it then we will remove it from path visited array not visited array
so that if in some other path if we again visit the node we will have the answer that no cycle 
will be found if gone forward in this path
then why maintaining path array ? so we can see if the visited node is visited in this traversal or some other
if some other then no cycle but if in this traversal then cycle detected


dfs(){
vis[node]=1;
pathvis[node]=1;

for(auto it:adj[node]){
	if(!vis[it]){
		if(dfs(it,adj,vis,pathvis)==true) return true;
	}
	else if(pathvis[it]){
		return true;
	}
}
pathvis[node]=0;
return false;
}
int main(){
int vis[v]={0};
int pathvis[v]={0};
for(int i=0;i<v;i++){
	if(!vis[i]){
		if(dfs(i,adj,vis,pathvis)==true) return true;
	}
}
return true;
}
*/

/* watch video 20 for example 

Find Eventual Safe state - dfs
all the nodes that has all the paths ends on terminal node(node which has outdegree 0)

any node who is a part of a cycle are not safe
any one leads to a cycle is not safe


bool dfsCheck(int node, vector<int> adj[], int vis[],int pathVis[], int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;
				return true;
			}
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;
	}

	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}
*/
int main()
{ 
 
 return 0;
}