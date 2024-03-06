#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void check(int n,vector<vector<char>>&grid){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                if(grid[i][j+1]=='1' && grid[i+1][j]=='1'){
                        cout<<"SQUARE"<<endl;
                        return;
                }
                else{
                    cout<<"TRIANGLE"<<endl;
                    return;
                }
            }
        }
    }
    return;
}
int main()
{ 
 int test;
 cin>>test;
 while(test){
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    check(n,grid);
    test--;
 }
 return 0;
}