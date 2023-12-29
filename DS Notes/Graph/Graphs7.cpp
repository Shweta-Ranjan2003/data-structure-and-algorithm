#include <iostream>
using namespace std;
/*
Dijkstra fails when graph has negative edges, or if graph has negative cycle then it gives TLE

*****Bellman Ford Algorithm****** - Shortest Path , helps to detect negative cycle
It works only on directed graph , if graph is undirected then convert it to directed like
if 1-2 weight=5
then do 1->2 w=5 and 2->1 w=5

1.Relax all the edges n-1 times sequentially
Relax - if(dist[u]+wt<dist[v]) dist[v]=dist[u]+wt

Initialize dist array with infinity and dist[0]=0;
loop n-1 times to all the edges (u,v,wt) and relax them n-1 time
at end you will have minimum distance stored in dist array for all edges

Q1) Why n-1 time?
In order to cover all the edges because in first iteration only the edge connected with 0th node will be updated and so on
Q2) How to detect neg cycle?
If after n-1th iteration , we do the nth iteration and value still reduces , it means graph contains negative cycle which is reducting its value at each iteration 


vector<int> dist(V,1e8);
dist[source]=0;
for(int i=0;i<V-1;i++){
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 and dist[u]+wt<dist[v]){
            dist[v]=dist[u]+wt;
        }
    }
}

//code is this much only but gfg states if it contains neg cycle then return arr of -1
//Nth relaxation to check neg cycle
for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 and dist[u]+wt<dist[v]){
            return {-1};
        }
    }
    return dist;

//V*E - tc
*/

/*
Bellman ,  dijkstra were single source algorithm where source node was only a single node
*****Floyd Warshall Algorithm****** - Multiple source node shortest path algorithm , detect neg cycle as well

adjacency matrix will be used as we have to store the shortest path from all node to all other node

1. Update your matrix with all the path for eg - at first you will update matrix of dist by taking all the paths VIA 0
then update it by taking path VIA 1  and so on . at last you will have shortest dist matrix
eg - if updating via zero then for going 1->2 we will store = min(dist[1][2], dist[1][0]+[0][2]);

For detecting neg cycle?
if costing of any node to itself is < 0 then graph contains neg cycle exist

for(int via=0;via<n;via++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
        }
    }
}
*/

/*
City with the smallest number of neighbors at a threshold distance
int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int via = 0; via < n; via++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (dist[i][j] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = i;
			}
		}
		return cityNo;
	}
};

*/


int main()
{ 
 
 return 0;
}

