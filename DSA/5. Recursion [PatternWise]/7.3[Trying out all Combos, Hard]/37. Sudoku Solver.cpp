// Link - https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char t[9] = {'1','2', '3', '4', '5', '6', '7', '8', '9'};
    bool isSafe(vector<vector<char>>& board, int row, int col, int num){
        for(int i=0; i<9; i++){
            if(i!=row && board[i][col]==t[num - 1]) return 0;
        }
        for(int j=0; j<9; j++){
            if(col!=j && board[row][j]==t[num - 1]) return 0;
        }

        int ii=row/3;
        int jj=col/3;

        for(int i=ii*3; i<(ii*3)+3; i++){
            for(int j=jj*3; j<(jj*3)+3; j++){
                if(!(i==row && j==col) && board[i][j]!='.' && board[i][j]==t[num - 1]) return 0;
            }
        }
        return 1;
    }

    bool solve(vector<vector<char>>& board, int row, int col){
        if(row == 9) return 1;
        if(col ==9) return solve(board, row+1, 0);
        if(board[row][col]!='.') return solve(board, row, col+1);

        for(int i=1; i<=9; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = t[i-1];
                if(solve(board, row, col+1)) return 1;
                board[row][col] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};