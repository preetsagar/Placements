// Link - https://leetcode.com/problems/word-search/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool solve(vector<vector<char>> &board, string word, int index, int i, int j, int n, int m) {
        if(index==word.size()) return 1;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.')  return 0;
        if(word[index]!=board[i][j]) return 0;

        int dx[4]={-1, 1,  0, 0};
        int dy[4]={ 0, 0, -1, 1};
        for(int itr=0; itr<4; itr++){
            int x=i+dx[itr];
            int y=j+dy[itr];
            
            char t=board[i][j];
            board[i][j] = '.';
            if(solve(board, word, index+1, x, y, n, m)) return 1;
            board[i][j] = t;

        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(solve(board, word, 0, i, j, board.size(), board[0].size())) return 1;
            }
        }
        return false;
    }
};
// ["A","B","C","E"]
// ["S","F","E","S"]
// ["A","D","E","E"]
