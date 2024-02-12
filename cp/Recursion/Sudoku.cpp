#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isValid(vector<vector<char>>&board,int row , int col , char c){
  for(int i=0;i<9;i++){
    if(board[row][i]==c) return false; //For checking in row
    if(board[i][col]==c) return false; //For checking in col
    if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false; //For checking in 3*3 matrice
  }
  return true;
}
bool solve(vector<vector<char>>&board){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(board[i][j]=='.'){
        for(char c='1';c<='9';c++){
          if(isValid(board,i,j,c)){
            board[i][j]=c;
            if(solve(board)==true) return true;
            else board[i][j]='.';
          }
        }
        return false;
      }
    }
  }
  return true;
}
int main()
{ 
 vector<vector<char>>board;
 solve(board);
 return 0;
}