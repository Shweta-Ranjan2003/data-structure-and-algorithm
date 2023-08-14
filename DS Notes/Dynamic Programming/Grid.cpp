#include <iostream>
using namespace std;
/*
1. Ninja's Training
N days long training and each day he can perform any one of these three activities
each activity have some merit , as ninja has to improve all his skill he cannot do same activity 
2 consecutive days , find max merit he can achive

t0 t1 t2
10 50 1 -> day 0
5 100 11 -> day 1

Greedy fails -> Try all possible ways
1. Index -> Day can be treated as index
2. Do stuffs
3. Find max

While choosing which task you can perform on a day its important to know
what skill we did on last day so that we do not perform the same task on
2 consecutive day

t0 t1 t2
2  1  3  d0
3  4  6  d1
10 1  6  d2
8  3  7  d3
we start from end to first day ,on last day we have 3 as last_task which means we can choose any in first time
f(day , last_task){
  if(ind==0){
    for(int i=0;i<=2;i++){
        if(i!=last_task){
        maxi=max(maxi,task[0,i]);
        }
    }
    return maxi;
  }
  int maxi=0;
  for(int i=0;i<=2;i++){
    if(i!=last_task){
        int points=task[day][i]+f(day-1,i);
        maxi = max(maxi,points);
    }
  }
  return maxi;
}


//****Memoization*****
dp[N][4];  //day task
f(day , last_task ,dp){
  if(day==0){
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last_task){
        maxi=max(maxi,points[0][i]);
        }
    }
    return maxi;
  }
  if(dp[day][last_task]!=-1) return dp[ind][last_task];
  int maxi=0;
  for(int i=0;i<=2;i++){
    if(i!=last_task){
        int point=points[day][i]+f(day-1,i,dp);
        maxi = max(maxi,point);
    }
  }
  return dp[day][last_task]=maxi;
}


//*******Tabulation - Bottom up******
t0 t1 t2
2  1  3  d0
3  4  6  d1
10 1  6  d2
8  3  7  d3
n=4 task=3
//base case will be if last=0 then we will take max of task 1,2 and so on
vector<vector<int>> dp(n,vector<int>(4,0));
dp[0][0]=max(arr[0][1],arr[0][2]);
dp[0][1]=max(arr[0][0],arr[0][2]);
dp[0][2]=max(arr[0][1],arr[0][0]);
dp[0][3]=max(arr[0][0],arr[0][1],arr[0][2]);

for(int day=1;day<n;day++){
    for(int last=0;last<4;last++){
       dp[day][last]=0;
       int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int point=arr[day][i]+ dp[day-1][i];
               dp[day][last]=max(dp[day][last],point);
            }
        }
    }
}
return dp[n-1][3];


//******Space Optimization******
vector<int>prev(4,0);
prev[0]=max(arr[0][1],arr[0][2]);
prev[1]=max(arr[0][0],arr[0][2]);
prev[2]=max(arr[0][1],arr[0][0]);
prev[3]=max(arr[0][0],arr[0][1],arr[0][2]);

for(int day=1;day<n;day++){
vector<int> temp(4,0);
for(int last=0;last<4;last++){
    temp[last]=0;
    for(int task=0;tast<3;task++){
        if(task!=last){
            temp[last]=max(temp[last],arr[day][task]+prev[day-1][task]);
        }
    }
}
prev=temp;
}
return prev[3];
*/


/*
Unique paths -> count paths
from top left cell to end cell
  0 1 2
0 s
1     r
ways=3;

1. Express everything in terms of index (row,col)
2. Do all stuffs
3. sum up all ways
starting from (1,2) (m-1,n-1) and reach (0,0)
f(i,j){
    if(i==0 and j==0) return 1;
    if(i<0 or j<0) return 0;

    int up=f(i-1,j);
    int left=f(i,j-1);

    return up+left;
}
 
//*****Memoization*******
dp[m][n];
f(i,j){
    if(i==0 and j==0) return 1;
    if(i<0 or j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int up= f(i-1,j,dp);
    int left=f(i,j-1,dp);

    return dp[i][j]=up+left;
}

if recursion is top down then tabulation is bottom up

//*****Tabulation******
1. declare base case
2. express all states in for loop
3. copy the recurence
dp[m][n];
dp[0][0]=1;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(i==0 && j==0) dp[0][0]=1;
        else{
            up=0;
            left=0;
           if(i>0) up=dp[i-1][j];
           if(j>0) left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
}
return dp[m-1][n-1];

}

//****Space optimization****
 prev[n]=0;
for(int i=0;i<m;i++){
    curr[n]=0;
    for(int j=0;j<n;j++){
        if(i==0 and j==0 ) curr[j]=1;
        else{
            int up=0;
            int left=0;
            if(i>0) up=prev[j];
            if(j>0) left=curr[j-1];
             curr[j]=up+left;

         }
      }
      prev=curr;
    }
    return prev[n-1];
}


//Combination solution 
         //ncr
         // RRD RDR DRR (2,3) matrix
        //n= n-1 + m-1 = n+m-2;
        //r=m-1 or r=n-1
        // 8c3 = 6*7*8/1*2*3
        int N=n+m-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res* (N-r+i)/i;
        }
        return (int)res;
*/

/*
Unique path 2 -> you cannot go via dead cell
f(i,j){
    if(i>=0 and j>=0 and mat[i][j]==1) return 0;
    if(i==0 and j==0) return 1;
    if(i<0 or j<0) return 0;
    int up=f(i-1,j);
    int left=f(i,j-1);

    return up+left;
}
//Memoization
 vector<vector<int> > dp(m,vector<int>(n,-1));
f(i,j,dp){
    if(i>=0 and j>=0 and mat[i][j]==1) return 0;
    if(i==0 and j==0) return 1;
    if(i<0 or j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j);
    int left=f(i,j-1);

    return dp[i][j]=up+left;
}
//Tabulation
vector<vector<int> > dp(n,vector<int>(m,-1));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
   if(i>0 and j>0 and mat[i][j]==-1)dp[i][j]=0;
   else if(i==0 and j==0) dp[i][j]=1;
   else{
    int up=0;
    int left=0;
    if(i>0)up=dp[i-1][j];
    if(j>0) left=dp[i][j-1];
    dp[i][j]=(up+left)%mod;
   }
    }
}
return dp[n-1][m-1];

//**Space optimization
vector<int>prev(m,0);
for(int i=0;i<n;i++){
    vector<int>curr(m,0);
    for(int j=0j<m;j++){
        if(mat[i][j]==-1) curr[j]=0;
        else if(i==0 and j==0) curr[j]=1;
        else{
            int up=0, left=0;
            if(i>0) up=prev[j];
            if(j>0) left=curr[j-1];
            curr[j]=(up+left)%mod;
        }
    }
    prev=curr;
}
return prev[m-1];
*/


/*
Minimum path sum
grid(n*m) = move from 0,0 to end while minimizing the path sum ->each path have its own path value
5  9  6
11 5  2
Greedy will not work here
Try all possible path -> recursion
starting from end
f(i,j){
    if(i==0 and j==0) return a[0][0];
    if(i<0 or j<0) return 1e9;
    
    int up=a[i][j]+f(i-1,j);
    int left=a[i][j]+f(i,j-1);

    return min(up,left);
}

vector<vector<int> > dp(m,vector<int>(n,-1));
f(i,j,dp){
    if(i==0 and j==0) return a[0][0];
    if(i<0 or j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=a[i][j]+f(i-1,j,dp);
    int left=a[i][j]+f(i,j-1,dp);

    return dp[i][j]=min(up,left);
}

//Tabulation
vector<vector<int> > dp(m,vector<int>(n,0));
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[m-1][n-1];
    

//Space optimization
vector<int> prev(m,0);
for(int i=0;i<n;i++){
    vector<int> temp(m,0);
    for(int j=0;j<m;j++){
        if(i==0 and j==0) temp[j]=mat[i][j];
        else{
            int up=mat[i][j];
            if(i>0) up+=prev[j];
            else up+=1e9;
            int left=mat[i][j];
            if(j>0) left+=temp[j-1];
            else left+=1e9;

            temp[j]=min(up,left);
        }
    }
    prev=temp;
}
return prev[m-1];
*/


/*
Triangle->
reach from 0,0 index to last row -> right triangle
Fixed starting point - variable ending point
1
2  3
3  6  7
8  9  6  10

f(i,j){
    if(i==N-1) return mat[i][j]
    down=mat[i][j]+f(i+1,j);
    diagonal=mat[i][j]+f(i+1,j+1);

    return min(down,diagonal);
}

//Memoization
vector<vector<int> > dp(n,vector<int>(n,-1));
f(i,j,dp){
if(dp[i][j]!=-1) return dp[i][j];
if(i==n-1) return triangle[i][j];
int down=triangle[i][j]+f(i+1,j,dp);
int diagonal = triangle[i][j]+f(i+1,j+1,dp);

return dp[i][j]=min(down,diagonal);
}

//Tabulation
 vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];

//Space optimization
vector<int> front(n,0), cur(n,0);
    
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    
    return front[0];
*/
int main()
{ 
 
 return 0;
}