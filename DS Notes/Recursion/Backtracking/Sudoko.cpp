#include <iostream>
using namespace std;
/*
Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.

         1. All the rows should be filled with numbers(1 – 9) exactly once.

         2. All the columns should be filled with numbers(1 – 9) exactly once.

         3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.

Note: Character ‘.’ indicates empty cell.
*/

/*
VALID SUDOKU - Determine if a 9 x 9 Sudoku board is valid. 
Only the filled cells need to be validated

bool isValid(vector<vector<char>>&board,int row,int col, char c){
  for(int i=0;i<9;i++){
      if(i!=col && board[row][i]==c) return false;
      if(i!=row && board[i][col]==c) return false;
      int rowCheck=3*(row/3)+i/3;
      int colCheck=3*(col/3)+i%3;
      if(rowCheck==row && colCheck==col) continue;
      if(board[rowCheck][colCheck]==c) return false;
  }
  return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                if(isValid(board,i,j,board[i][j])==false) return false;
            }
        }
        }
        return true;
    }
*/

/*
**********SUDOKU SOLVER**********
solve a Sudoku puzzle by filling the empty cells.
Since we have to fill the empty cells with available possible numbers and we can also have multiple 
solutions, the main intuition is to try every possible way of filling the empty cells. 
And the more correct way to try all possible solutions is to use recursion. In each call to the 
recursive function, we just try all the possible numbers for a particular cell and transfer the 
updated board to the next recursive call.

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
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
*/
int main()
{ 
 
 return 0;
}