#include <iostream>
#include <bits/stdc++.h>
//Range minimum query - partially accepted
using namespace std;
void build(long long int arr[],long long int tree[],long long int s,long long int e,long long int idx){
    if(s==e){
        tree[idx]=arr[s];
        return;
    }
    long long int mid=s+(e-s)/2;
    build(arr,tree,s,mid,2*idx);
    build(arr,tree,mid+1,e,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;
}

long long int query(long long int tree[],long long int s,long long int e,long long int idx,long long int qs,long long int qe){
    if(s>qe || e<qs){
        return INT_MAX;
    }
    if(s>=qs && s<=qe)return tree[idx];
    long long int mid=s+(e-s)/2;
    long long int left=query(tree,s,mid,2*idx,qs,qe);
    long long int right=query(tree,mid+1,e,2*idx+1,qs,qe);
    return min(left,right);
}
void update(long long int tree[],long long int s,long long int e,long long int idx,long long int i,long long int val){
    if(i<s || i>e){
        return;
    }
    if(s==e){
        tree[idx]=val;
        return;
    }
	long long int mid=s+(e-s)/2;
    update(tree,s,mid,2*idx,i,val);
    update(tree,mid+1,e,2*idx+1,i,val);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;
}
int main() {
	long long int n;
	cin>>n;
	long long int queries;
	cin>>queries;
	long long int arr[n];
	for(long long int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long int tree[4*n+1];
	build(arr,tree,0,n-1,1);
	for(long long int i=0;i<queries;i++){
		char type;
		cin>>type;
		long long int qs;
		cin>>qs;
		long long int qe;
		cin>>qe;
		if(type=='q'){
			cout<<query(tree,0,n-1,1,qs-1,qe-1)<<endl;
		}
		else{
			update(tree,0,n-1,1,qs-1,qe);
		}
	}
	return 0;
}