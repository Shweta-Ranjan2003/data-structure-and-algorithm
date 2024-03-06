/*
Shortest Grid Path
Given a two dimensional grid, each cell of which contains integer cost which represents a cost to traverse through that cell, 
we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum.

Note : It is assumed that negative cost cycles do not exist in input matrix.


Input

Grid as shown above (input given as vector<vector<int> > grid ).
Hint : Use grid.size() to get rows and grid[0].size() to get columns.

31 100 64 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20
Output

An integer denoting the minimum cost.

327 
Explanation

Cells in green are the cells which are visited to complete this route 
327 (= 31 + 10 + 13 + 47 + 65 + 12 + 18 + 
6 + 33 + 11 + 20 + 41 + 20)
*/
#include<bits/stdc++.h>
using namespace std;

int shortest_path(vector<vector<int> > grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[0][0]=grid[0][0];
    //dist,i,j
    set<pair<int,pair<int,int>>>st;
    st.insert({dist[0][0],{0,0}});
    int delr[]={-1,1,0,0};
    int delc[]={0,0,-1,1};
    while(!st.empty()){
        auto it=st.begin();
        int curr_dist = it->first;
        int i = it->second.first;
        int j = it->second.second;
        st.erase(it);
        for(int k=0;k<4;k++){
            int row=i+delr[k];
            int col=j+delc[k];
            if(row>=0 and col>=0 and row<n and col<m and curr_dist+grid[row][col]<dist[row][col]){
                
                pair<int,pair<int,int>> temp={dist[row][col],{row,col}};
                if(st.find(temp)!=st.end()){
                    st.erase(st.find(temp));
                }
                dist[row][col]=curr_dist+grid[row][col];
                st.insert({dist[row][col],{row,col}});
            }
        }
    }
    return dist[n-1][m-1];
}


/*
Astronaut Pairs
The member states of the UN are planning to send people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. 
Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example

n = 4

astronauts = [1,2] [2,3]

There are 4 astronauts numbered 0 through 3. Astonauts grouped by country are [0] and [1,2,3]. There are 3 pairs to choose from [0,1], [0,2] and [0,3].



Input

Input contains the number N : denoting number of astronauts and and list L denoting the pairs of astronauts from the same country.

N = 5
vector<pair<int,int> > astronauts = {{0,1}, {2,3} , {0,4}};
Output

6

There are 6 ways to choose a pair (0,2) (0,3) (1,2) (1,3) (4,2) and (4,3) as astronauts (0,1,4) belong to country 1 and (2,3) belong to another.
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis,int&count){
    vis[node]=1;
    count++;
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,adj,vis,count);
        }
    }
}
int count_pairs(int n, vector<pair<int,int> > ast){
    vector<int>vis(n,0);
    vector<int>adj[n];
    for(auto it:ast){
        int u=it.first;
        int v=it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int answer=1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int count=0;
            dfs(i,adj,vis,count);
            int remaining=n-count;
            answer+=(count*remaining);
        }
    }
    return answer/2;
}

/*
Graph Sequence (Graph + DP)
Complete the following function which takes in an implicit graph (2D Matrix) and returns the length of longest increasing path sequence inside it.
A  path can start from any node (x,y), and is increasing if each of its elements is strictly greater than previous element.
(Assume - 4 way connectivity, each cell is connected with Top, Left, Up & Down)

Sample Input

 [
  [0,  2,  4,  3,  2],
  [7,  6,  5,  5,  1],
  [8,  9,  7, 18, 14],
  [5, 10, 11, 12, 13],
]
Sample output

15

Explanation

Look at the following path that starts from 1 and ends at 18. It has 15 nodes.



Expected Time Complexity
O(MN) where M is the number or rows, N is the number of columns.
*/

#include<bits/stdc++.h>
using namespace std;
int delr[]={-1,1,0,0};
int delc[]={0,0,-1,1};
void dfs(int i,int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&vis,vector<vector<int>>&dp){
    vis[i][j]=1;
    int cnt=0;
    for(int k=0;k<4;k++){
        int row=i+delr[k];
        int col=j+delc[k];
        if(row>=0 and col>=0 and row<n and col<m and matrix[row][col]>matrix[i][j]){
            if(vis[row][col]==1){
                cnt=max(cnt,1+dp[row][col]);
            }
            else{
                dfs(row,col,n,m,matrix,vis,dp);
                cnt=max(cnt,1+dp[row][col]);
            }
        }
    }
    dp[i][j]=cnt;
    return;
}
int longestPathSequence(vector<vector<int> > matrix){
   int n=matrix.size();
   int m=matrix[0].size();
   vector<vector<int>>vis(n+1,vector<int>(m+1,0));
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   int ans=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           dfs(i,j,n,m,matrix,vis,dp);
           ans=max(ans,1+dp[i][j]);
       }
   }
   return ans;
}