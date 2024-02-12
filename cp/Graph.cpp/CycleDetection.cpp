#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void addEdge2(vector<int> adj2[], int u, int v)
{
	adj2[u].push_back(v);
}

//bfs
bool isCyclicConnected(vector<int> adj[], int s,
						int V, vector<bool>& visited)
{
	vector<int> parent(V, -1);
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
				parent[v] = u;
			}
			else if (parent[u] != v)
				return true;
		}
	}
	return false;
}

bool isCyclicDisconnected(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++)
		if (!visited[i] && isCyclicConnected(adj, i,
										V, visited))
			return true;
	return false;
}


// bool dfscycle(int src,vector<int>adj[],vector<bool>&vis,int parent){
// vis[src]=true;
// for(auto nbr:adj[src]){
//     if(!vis[nbr]){
//         if(dfscycle(nbr,adj,vis,src)==true) return true;
//     }
//     else if(nbr!=parent)return true;
// }
// return false;
// }


//Directed cyclic graph detection 
bool dfscycle2(int src,vector<int>adj[],vector<bool>&vis,vector<bool>&pathvis){
vis[src]=true;
pathvis[src]=true;
for(auto nbr:adj[src]){
    if(!vis[nbr]){
        if(dfscycle2(nbr,adj,vis,pathvis)==true) return true;
    }
    else if(pathvis[nbr])return true;
}
pathvis[src]=false;
return false;
}

int main()
{
	// int V = 6;
	// vector<int> adj[V];
	// addEdge(adj, 0, 1);
	// addEdge(adj, 1, 2);
	// addEdge(adj, 2, 3);
	// addEdge(adj, 3, 4);
	// addEdge(adj, 3, 5);

	// if (isCyclicDisconnected(adj, V))
	// 	cout << "Yes";
	// else
	// 	cout << "No";

    // vector<bool>vis(V,false);
    //  if(dfscycle(0,adj,vis,-1)){
    //     cout<<"YES";
    //  }
    //  else cout<<"NO";

    int V2 = 4;
	vector<int> adj2[V2];
	addEdge2(adj2, 0, 1);
	addEdge2(adj2, 0, 2);
	addEdge2(adj2, 1, 3);
	addEdge2(adj2, 3, 2);
	addEdge2(adj2, 3, 0);
    vector<bool>vis(V2,false);
    vector<bool>pathvis(V2,false);
    if(dfscycle2(0,adj2,vis,pathvis))cout<<"Yes";
    else cout<<"No";
	return 0;
}
