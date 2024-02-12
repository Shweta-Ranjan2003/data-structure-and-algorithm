#include <iostream>
#include <bits/stdc++.h>
//minimum element query of given range in an array
//GSS1 - Can you answer these queries I
//Range minimum query - partially accepted
//GSS3
using namespace std;
void build(int arr[],int tree[],int s,int e,int idx){
    if(s==e){
        tree[idx]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    build(arr,tree,s,mid,2*idx);
    build(arr,tree,mid+1,e,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;
}

int query(int tree[],int s,int e,int idx,int qs,int qe){
    if(s>qe || e<qs){
        return INT_MAX;
    }
    if(s>=qs && s<=qe)return tree[idx];
    int mid=(s+e)/2;
    int left=query(tree,s,mid,2*idx,qs,qe);
    int right=query(tree,mid+1,e,2*idx+1,qs,qe);
    return min(left,right);
}

//Point update
void update(int tree[],int s,int e,int idx,int i,int val){
    if(i<s || i>e){
        return;
    }
    if(s==e){
        tree[idx]=val;
        return;
    }
    int mid=(s+e)/2;
    update(tree,s,mid,2*idx,i,val);
    update(tree,mid+1,e,2*idx+1,i,val);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;
}

//Range update
void updateRange(int tree[],int s,int e,ind idx,int us,int ue,int val){
    if(us>e || ue<s)return;
    if(s==e){
        tree[idx]+=val;
        return;
    }
    int mid=(s+e)/2;
    updateRange(tree,s,mid,2*idx,us,ue,val);
    updateRange(tree,mid+1,e,2*idx+1,us,ue,val);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;
}
int main()
{ 
 int arr[]={3,5,1,6,2,7,4};
 int n=7;
 int tree[4*7+1];
 build(arr,tree,0,n-1,1);
//  for(int i=1;i<=13;i++){
//     cout<<tree[i]<<" "; //1 1 2 3 1 2 4 3 5 1 6 2 7
//  }
 cout<<query(tree,0,n-1,1,3,5);
 return 0;
}