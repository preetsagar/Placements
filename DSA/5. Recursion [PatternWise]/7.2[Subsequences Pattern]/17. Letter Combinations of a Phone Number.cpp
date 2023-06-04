// Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, string> m;
    
    void solve(vector<string> &ans, string digits, string s, int index){
        if(s.size()==digits.size()){
            if(s.size()!=0)
                ans.push_back(s);
            return;
        }

        for(int i=0; i<m[digits[index]-'0'].size(); i++){
            s.push_back(m[digits[index]-'0'][i]);
            solve(ans, digits, s, index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        solve(ans, digits, "", 0);
        return ans;
    }
};