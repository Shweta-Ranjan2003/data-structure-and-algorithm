#include <bits/stdc++.h>
using namespace std;
//O(4 alpha) - constant
class DisjointSet{
    vector<int>rank,parent,sizee;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sizee.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            sizee[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
          parent[ulp_v]=ulp_u;
          rank[ulp_u]++;  
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(sizee[ulp_u]<sizee[ulp_v]){
            parent[ulp_u]=ulp_v;
            sizee[ulp_v]+=sizee[ulp_u];
        }
        else{
          parent[ulp_v]=ulp_u;
          sizee[ulp_u]+=sizee[ulp_v];  
        }

    }
};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //check 3 and 7 are same component or not
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    ds.unionByRank(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }


    //DisjointSetBySizee
    DisjointSet ds2(7);
    ds2.unionBySize(1,2);
    ds2.unionBySize(2,3);
    ds2.unionBySize(4,5);
    ds2.unionBySize(6,7);
    ds2.unionBySize(5,6);
    //check 3 and 7 are same component or not
    if(ds2.findUPar(3)==ds2.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    ds2.unionBySize(3,7);
    if(ds2.findUPar(3)==ds2.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    return 0;
}