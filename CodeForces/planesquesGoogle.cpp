#include <bits/stdc++.h>
using namespace std;
bool isVerticallySymm(vector<pair<int,int>>points){
    unordered_map<int,vector<int>>coordinates;
    for(auto it:points){
        int x=it.first;
        int y=it.second;
        coordinates[y].push_back(x);
    }
    for(auto it:coordinatees){
        sort(it.second.begin(),it.second.end());
        int n=it.second.size();
        int start=0;
        int end=n-1;
        float los;
        bool found=false;
        while(start<end){
            float output=(it.second[start]+it.second[end])/2;
            if(found==false){
                los=output;
                found=true;
            }
            else{
                if(output!=los){
                    return false;
                }
            }
            start++;
            end--;
        }
        if(start==end){
            if(found==true){
                if(los!=it.second[start]){
                    return false;
                }
            }
            else{
                los=it.second[start];
            }
        }
    }
    return true;
}
int main()
{ 
 
 return 0;
}