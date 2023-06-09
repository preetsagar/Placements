// Link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int node[21] = {0};
    int solve(bool g[101][101], int n, int m, int i){
        if(i==n) return 1;
        
        for(int c=1; c<=m; c++){
            int can_paint=1;
            for(int j=0; j<n; j++){
                if(g[i][j] && node[j]==c){
                    can_paint = 0;
                }
            }
            if(can_paint){
                node[i] = c;
                if(solve(g, n, m, i+1)) return 1;
                node[i] = 0;
            }
        }
        return 0;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        return solve(graph, n, m, 0);
    }
};