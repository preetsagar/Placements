// Link - https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPlacable(vector<string> ds, int row, int col, int n){
        
        int i, j;

        // check up
        i=row; j=col;
        while(i>=0){
            if(ds[i][j]=='Q') return 0;
            i--;
        }

        // check up-right
        i=row; j=col;
        while(i>=0 && j<n){
            if(ds[i][j]=='Q') return 0;
            i--;
            j++;
        }
        
        // check up-left
        i=row; j=col;
        while(i>=0 && j>=0){
            if(ds[i][j]=='Q') return 0;
            i--;
            j--;
        }
        return 1;
    }
    void solve(vector<vector<string>> &ans, int n, int row, vector<string> ds){
        if(row==n){
            ans.push_back(ds);
            return;
        }
        for(int col=0; col<n; col++){
            if(isPlacable(ds, row, col, n)){
                ds[row][col] = 'Q';
                solve(ans, n, row+1, ds);
                ds[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>ds(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            ds[i] = s;
        }
        solve(ans, n, 0, ds);
        return ans;
    }
};