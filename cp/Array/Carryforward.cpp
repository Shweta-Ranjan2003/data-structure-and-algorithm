#include <iostream>
#include <vector>
using namespace std;
/*
Calc no of pairs (i,j) such that a[i]=='a' and a[j]=='g' , i<j
right to left fowarding information of count of g so its carry forwarding
g s a g l a a e g a
*/
int count(string s){
    int n=s.size();
    int cntg=0;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='g')cntg++;
        else if(s[i]=='a')ans+=cntg;
    }
    return ans;
}

//Leaders in array
//a[i] is a leader if it is strictly > than elements on right
int leader(vector<int>&arr){
    int n=arr.size();
    int maxi=arr[n-1];
    int cnt=1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi){
            maxi=arr[i];
            cnt++;
        }
    }
    return cnt;
}

//Given an array a find smallest subarray that contains both min and max element of the array
//duplicates can be present
int range(vector<int>&arr){
    int n=arr.size();
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    bool foundmin=false;
    bool foundmax=false;
    int len=INT_MAX;
    int small;
    int large;
    for(int i=0;i<n;i++){
        if(arr[i]==mini){
           foundmin=true;
           small=i;
           if(foundmax==true){
            len=min(len,(small-large+1));
           }
        }
        if(arr[i]==maxi){
            foundmax=true;
            large=i;
           if(foundmin==true){
              len=min(len,(large-small+1));
           }
        }
    }
    return len;
}
int main()
{ 
 //cout<<count("gsaglaaega");
//  vector<int>arr{15,-1,7,2,5,4,2,3};
//  cout<<leader(arr);

//vector<int>arr{1,6,4,6,5,1,5,2,6,4,4,2,1,5};
vector<int>arr{1,1,1,1,1};
cout<<range(arr);
 return 0;
}