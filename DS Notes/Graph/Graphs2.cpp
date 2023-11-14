#include <iostream>
using namespace std;

/*
Number of Provinces
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
A province is a group of directly or indirectly connected cities and no other cities outside of the group
void dfs(int node , vector<int>adj[],vector<int>&vis){
vis[node]=1;
for(auto it: adj[node]){
    if(!vis[it]){
        dfs(it,adj,vis);
    }
}
}
    int findCircleNum(vector<vector<int>>& adjmat) {
        int n=adjmat.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjmat[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
             count++;
             dfs(i,adj,vis);
            }
        }
        return count;

    }
*/


/*
Number of islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        //All possible 4 directions
        int delR[]={-1,0,1,0};  //when row-1 or +1 then col will be same and when col-1 or +1 then row will be same
        int delC[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(!(vis[i][j]) and grid[i][j]=='1'){
                count++;
                vis[i][j]=1;
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nrow=row+delR[k];
                        int ncol=col+delC[k];
                        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]!='0'){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                }
              }
            }
        }
        return count;
    }
*/


/*
Flood Fill Algorithm
You will be given starting row and col and new color then you have to 
color every element connected to that index and is of same color with the new color
1 1 1
2 2 0
2 2 2
new color=3
sr=2 sc=0
1 1 1
3 3 0
3 3 3


can be solved with both bfs and dfs
dfs(row,col,ans,img,newColor,delRow,delCol,initial){
    ans[row][col]=newColor;
    int n=img.size();
    int m=img[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and img[nrow][ncol]==initial and ans[nrow][ncol]!=newColor){
        dfs(nrow,ncol,ans,img,newColor,delRow,delCol,initial);
        }
    }

}
int main(){
int initial=img[sr][sc];
vector<vector<int>>ans=img;
int delRow[]={-1,0,+1,0};
int delCol[]={0,+1,0,-1};
dfs(sr,sc,ans,img,newColor,delRow,delCol);
}
*/

/*
Rotten Oranges
How much time required to rotten all the oranges , rotten orange will rotten all neigbor(top,down,left,right) in  unit time
if cannot rotten all then return -1 , 0 means no orange , 1 means fresh orange and 2 means rotten orange

0 1 2
0 1 1
2 1 1

bfs queue ->
(2,0,0) (0,2,0) (2,1,1) (1,2,1) (0,1,1) (1,1,2) (2,2,2)
 i j time

 int orangesRotting(vector < vector < int >> & grid) {
      // figure out the grid size
      int n = grid.size();
      int m = grid[0].size();

      // store {{row, column}, time}
      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if cell contains rotten orange
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            // mark as visited (rotten) in visited array
            vis[i][j] = 2;
          }
          // if not rotten
          else {
            vis[i][j] = 0;
          }
          // count fresh oranges
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
      // delta row and delta column
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // exactly 4 neighbours 
        for (int i = 0; i < 4; i++) {
          // neighbouring row and column
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          // check for valid cell and 
          // then for unvisited fresh orange
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            // push in queue with timer increased
             q.push({{nrow, ncol}, t + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

      // if all oranges are not rotten
      if (cnt != cntFresh) return -1;

      return tm;

    } 
*/

/*
Detect cycle in an undirected graph using bfs
  2  5
1      7
  3  6
  4

queue node and where it came from
queue- (1,-1) (2,1) (3,1) (5,2) (4,3) (6,3) (7,5)
now when will check adjacency list of 6 it will show 3,7 but we just came from
3(checking visited array) so will not go there and 7 is already marked visited in vis array
that means any other node also came and touch 7 so there is a cycle

bool detect(int src,vector<int>adj[],int vis[]){
  vis[src]=1;
  queue<pair<int,int>>q;
  q.push({src,-1});
  while(!q.empty()){
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
    for(auto it:adj[node]){
      if(!vis[it]){
        vis[it]=1;
        q.push({it,node});
      }
      else if(parent!=it){
        return true;
      }
    }
  }
  return false;
}

What if graph is broken into connected component
1 2 4       5      7
  3         6     8 9

now if traversing for 1 doesn't find cycle there is no point traversing for 2 3 4 again
now check for 5 then for 7 and you will find cycle for 7
int main(){
for(i=1;i<=n;i++){
  if(!vis[i]){
    if(detect(i)==true) return true;
  }
}
return false;
}
*/

/*
Detect cycle in undirectec graph using dfs
  2  5
1      7
  3  6
  4

If you are starting from 1 and again coming back to 1 that means cycle
dfs(1,-1) - node and parent node
dfs(2,1) //adjacency list contains 1,5 but cannot say cycle because 1 already marked vis because it's the parent node of 2
dfs(5,2)
dfs(7,5)
dfs(6,7)
dfs(3,6)
dfs(1,3) //1 already marked in vis and its not the parent node of 3 which means cycle
//If got true from a call then dont run any futher dfs call just return true

bool dfs(int node,int parent,vector<int>vis[],vector<int> adj[]){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      if(dfs(it,node,vis,adj)==true) return true;
    }
    else if(it!=parent) return true;
  }
  return false;
}
int main(){
  int vis[v]={0};
  for(int i=0;i<v;i++){
    if(!vis[i]){
      if(dfs(i,-1,vis,adj)==true) return true;
    }
  }
  return false;
}

*/


/*
Distance of nearest cell having 1 direction-up down left right
0 0 0
0 1 0
1 0 1

nearest 1 calculated
2 1 2
1 0 1
0 1 0

bfs - (1,1,0),(2,0,0),(2,2,0),(0,1,1),(1,2,1),(2,1,1),(1,0,1),(0,2,2),(0,0,2)
       i j steps

vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(); 
	    int m = grid[0].size(); 
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    // <coordinates, steps>
	    queue<pair<pair<int,int>, int>> q; 
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 1
	            if(grid[i][j] == 1) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    return dist; 
	}
*/

/*
Replace O's with X's - you can replace o with x if they are covered with x from top bottom left and right
which means if there is any o in boundary line then that o and every o connected to it cannot be converted to
x because they are not covered with x in all 4 direction.

can be done with both dfs and bfs , here using dfs
[["X","X","X","X"]
 ["X","O","O","X"]
 ["X","X","O","X"]
 ["X","O","X","X"]]

[["X","X","X","X"]
 ["X","X","X","X"]
 ["X","X","X","X"]
 ["X","O","X","X"]]

void dfs(){
  vis[row][col]=1;
  int n=mat.size();
  int m=mat[0].size();
  for(int i=0;i<4;i++){
    int nrow=row+delrow[i];
    int ncol=col+delcol[i];
    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and mat[nrow][ncol]=='O'){
      dfs(nrow,ncol,vis,mat,delrow,delcol);
    }
  }
}
int main(){
vector<vector<int>>vis(n,vector<int>(m,0));
int delrow[]={-1,0,1,0};
int delcol[]={0,1,0,-1}
for(int j=0;j<m;j++){
  if(!vis[0][j] and mat[0][j]=='O'){
    dfs(0,j,vis,mat,delrow,delcol);
  }
  if(!vis[n-1][j] and mat[n-1][j]=='O'){
    dfs(n-1,j,vis,mat,delrow,delcol);
  }
}
for(int i=0;i<m;i++){
  if(!vis[i][0] and mat[i][0]=='O'){
    dfs(i,0,vis,mat,delrow,delcol);
  }
  if(!vis[i][m-1] and mat[i][m-1]=='O'){
    dfs(i,m-1,vis,mat,delrow,delcol);
  }
}

for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(!vis[i][j] and mat[i][j]=='O'){
      mat[i][j]='X';
    }
  }
}
return mat;
}
*/

/*
Same boundary question can be solved with bfs lets see how
Number of enclaves
int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m] = {0}; 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
*/

/*
Number of distinct Islands
1 1 0 1 1
1 0 0 0 0
0 0 0 1 1
1 1 0 1 0

set - (0,0)(0,1)(1,0) 
now (2,3)(2,4)(3,3) is also identital to the prev one but how to identify
minus the coordinates with base (2,3) then you will get (0,0)(0,1)(1,0) same for (0,0)(0,1)(1,0)

make sure to follow order if going right first then same for all

void dfs(int row, int col, vector < vector < int >> & vis,
      vector < vector < int >> & grid, vector < pair < int, int >> & vec, int row0, 
      int col0) {
      // mark the cell as visited
      vis[row][col] = 1;

      // coordinates - base coordinates
      vec.push_back({
        row - row0,
        col - col0
      });
      int n = grid.size();
      int m = grid[0].size();

      // delta row and delta column
      int delrow[] = {-1, 0, +1, 0}; 
      int delcol[] = {0, -1, 0, +1}; 

      // traverse all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid unvisited land neighbour coordinates 
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
      }
    }
  public:
    int countDistinctIslands(vector < vector < int >> & grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector < vector < int >> vis(n, vector < int > (m, 0));
      set < vector < pair < int, int >>> st;

      // traverse the grid
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if not visited and is a land cell
          if (!vis[i][j] && grid[i][j] == 1) {
            vector < pair < int, int >> vec;
            dfs(i, j, vis, grid, vec, i, j);
            // store in set
            st.insert(vec);
          }
        }
      }
      return st.size();
    }

*/
int main()
{ 
 
 return 0;
}