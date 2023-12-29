#include <iostream>
#include <vector>
using namespace std;
/*
Minimum Spanning Tree - 
Spanning tree - A tree in which we have N nodes and N-1 edges and all nodes are reachable from each other

Now there can be multiple spanning trees but the one with the minimum sum of edges is known as MST of the graph
*/

/*
Prim's Algorithm ->MST
priority queue - wt,node,parent       (min heap)
vis array initially marked as 0

start with any given node (0,0,-1) in pq
take it out and mark 0th node in vis as 1
stand at 0 and look at adjacent node then put (2,1,0)
then put (1,2,0) , these both are directly connected to 0 
now because its mean hip then second node will come at top because it has less wt

And when marking vis add the node and parent node in MST
and add sum of the edge wt.

priority_queue<pair<int, int>,
vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
*/

/*
******Disjoint Set******
If the graph is broken into two connected component
1-2-3-4
5-6-7
and we want to find is 1 and 5 connected then dfs bfs will take O(N+E) time
but disjoint set will take constant time by using two things:-

find parent()
Union()->rank
       ->size


union(u,v) - rank (log n)
1. find ultimate parent of u&v ; pu,pv
2. find rank of pu,pv
3. connect smaller rank to larger rank always  
4. if the rank of both was same then increase rank of the one you kept at top by one
5. update the parent of the node you kept below

When we have to check where the two nodes are connected or not we will check their ultimate parents are same or not

*****Path compression*****
we will directly link the node to ultimate parent and update the parent vector


Union by size- 
in union by rank after path compression the rank is distorted so we use size instead

tc- 4 alpha
*/
class DisjointSet {
public:
    vector<int> rank, parent,size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/*
Kruskal's Algorithm - MST
sort all the edges acc. to wt (wt,u,v)
connect all the node in sequential order of node wt and which do not have same ultimate parent 

Use same code of disjoint set just add
int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
*/

/*
Number of Provinces
You can tell number of provinces by counting unique ultimate parents of all node
or the node whose ultimate parent is the node itself is a different province

int numproviences(vector<vector<int>>adj , int v){
    DisjointSet ds(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1){
                ds.unionBySize(i,j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<v;i++){
        if(ds.findUPar(i)==i){
            cnt++;
        }
    }
    return cnt;
}
*/
int main()
{ 
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    DisjointSet ds2(7);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    ds2.unionBySize(6, 7);
    ds2.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds2.findUPar(3) == ds2.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds2.unionBySize(3, 7);

    if (ds2.findUPar(3) == ds2.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
 return 0;
}