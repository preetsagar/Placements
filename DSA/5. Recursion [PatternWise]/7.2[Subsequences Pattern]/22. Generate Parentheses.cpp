// Link - https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<string> &ans, int left, int right, string s){
        if(left==0 and right==0){
            ans.push_back(s);
            return;
        }
        if(left){
            solve(ans, left-1, right+1, s+'(');
        }
        if(right){
            solve(ans, left, right-1, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n, 0, "");
        return ans;
    }
};