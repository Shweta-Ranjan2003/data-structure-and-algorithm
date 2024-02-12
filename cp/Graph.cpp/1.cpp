#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Snake and ladder
*/
class Graph{
    Graph(int len){
        vector<int>board(len+1,0);
        //add snakes and ladders
    }
    void BFS(){
    for(int s=0;s<36;s++){
        for(int dice=1;dice<=6;dice++){
            int distance=s+dice;
            if(distance<=36) distance+=board[distance];
            if(distance<=36){
                g.addEdge(s,distance,true);
            }
        }
    }
    }
};
int main()
{ 
 Graph g(37);
 return 0;
}