#include <bits/stdc++.h>
using namespace std;
long long ans;
class Graph{
    unordered_map<int,list<pair<int,int>>> network;
    int nodes;
  public:
    Graph(int n){
        nodes=n;
    }
    void addEdge(int u,int v,int distance){
        network[u].push_back(make_pair(v,distance));
        network[v].push_back(make_pair(u,distance));
    }
    int dfsHelper(int vertex,bool visited[],int distanceTravelled){
        visited[vertex]=true;
        int count=1;
        for(auto neighbour:network[vertex]){
           if(!visited[neighbour.first]){
               int currCount=dfsHelper(neighbour.first,visited,neighbour.second);
                ans+=2*(neighbour.second)*min(currCount,nodes-currCount);
                count+=currCount;
           } 
        }
        return count;
    }
    void dfs(int vertex){
        bool visited[nodes+1];
        for(int i=1;i<=nodes;i++){
            visited[i]=false;
        }
        dfsHelper(vertex,visited,0);
    }
};
int main(){
    int t;cin>>t;
    int number=0;
    while(t--){
        number++;
        ans=0;
        int n;cin>>n;
        Graph graph(n);
        for(int i=0;i<n-1;i++){
            int x,y,d;cin>>x>>y>>d;
            graph.addEdge(x,y,d);
        }
        graph.dfs(1);
        cout<<"Case #"<<number<<": "<<ans<<endl;
    }
    return 0;
}