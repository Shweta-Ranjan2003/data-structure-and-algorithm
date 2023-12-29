#include <iostream>
#include <vector>
using namespace std;
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
Connecting the graph:-
Number of Operations to Make Network Connected - DSU
Given a graph you can remove some edges from the graph and use those 
edges to make the graph connected to the rest of the components but 
you can remove edges in a way that graph remains still 
connected(all nodes have path to all remaining nodes).
Return minimum no. of operations to make a graph connected

if i can somehow figure out the no. of connected components the operation - n-1
if there are 3 different components i need 2 edges to connect all

1. Count the extra edges
2. ans=n-1 , if(extraedges>=ans)return ans
   else return -1

int solve(int n, vector<vector<int>>&edge){
    DisjointSet ds(n);
    int cntExtras=0;
    for(auto it: edge){
        int u=it[0];
        int v=it[1];
        if(ds.findUPar(u)==ds.findUPar(v)){
            cntExtras++;
        }
        else{
            ds.unionBySize(u,v);
        }
    }
    int cntC=0;
    for(int i=0;i<n;i++){
        if(ds.parent[i]==i)cntC++;
    }
    int ans=cntC-1;
    if(cntExtras>=ans) return ans;
    return -1;
}
*/

/*
Accounts Merge - DSU / Merging Details

 vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
*/

/*
Number of islands 2 / Number of Islands
0-sea
1-land
//We are using DSU to determine if one island we are connecting to another island
lets say right to it then cnt-- will happend but what if there is one island below it
and that below island is already connected to that right island in that case cnt will 
not get -- . so to check it we will have to maintain ultimate parent of all island/node

bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

int main()
DisjointSet ds(n*m);
int vis[n][m];
memset(vis,0,sizeof vis);
int cnt=0;
vector<int>ans;
for(auto it:operators){
    int row=it[0];
    int col=it[1];
    if(vis[row][col]==1){
        ans.push_back(cnt);
        continue;
    }
    vis[row][col]=1;
    cnt++;

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    for(int ind=0;ind<4;ind++){
        int adjr=row+dr[ind];
        int adjc=col+dc[ind];
        if(isValid(adjr,adjc,n,m)){
            if(vis[adjr][adjc]==1){
                int nodeNo=row*m+col;
                int adjNodeNo=adjr*m+adjc;
                if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                    cnt--;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
    }
    ans.push_back(cnt);
}
return ans;
*/

/*
Making a Large Island - DSU / Maximum connected group

bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
*/
int main()
{ 
 
 return 0;
}