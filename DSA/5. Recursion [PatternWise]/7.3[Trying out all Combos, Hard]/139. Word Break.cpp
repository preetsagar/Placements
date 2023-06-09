// Link - https://leetcode.com/problems/word-break/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[301];
    bool solve(string &s, vector<string>& dict, int i){
        if(i==s.size()) return 1;

        string t="";
        int ans=0;
        if(dp[i]!=-1)   return dp[i];
        for(int itr=i; itr<s.size() && itr<i+20; itr++){
            t += s[itr];
            if(find(dict.begin(), dict.end(), t) != dict.end()){
                ans = ans | solve(s, dict, itr+1);
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        return solve(s, wordDict, 0);
    }
};