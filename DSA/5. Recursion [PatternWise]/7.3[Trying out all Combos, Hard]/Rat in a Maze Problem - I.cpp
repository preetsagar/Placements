// Link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    void solve(vector<string> &ans, vector<vector<int>> &m, int n, int i, int j, string s){
        if(i==n-1 and j==n-1 and m[i][j]==1){
            ans.push_back(s);
            return;
        }
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0) return;
        if(m[i][j]==-1) return;
        
        int dx[4]={-1, 0, 1,  0};
        int dy[4]={ 0, 1, 0, -1};
        char dir[4] = {'U', 'R', 'D', 'L'};
        for(int itr=0; itr<4; itr++){
            int t=m[i][j];
            int x = i+dx[itr];
            int y = j+dy[itr];
            
            m[i][j] = -1;
            solve(ans, m, n, x, y, s+dir[itr]);
            m[i][j] = t;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        solve(ans, m, n, 0, 0, "");
        return ans;
    }
};