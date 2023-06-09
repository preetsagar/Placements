// Link - https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        if(s.size()<=1) return 1;
        int i=0, j=s.size()-1;
        while(i<j){
           if(s[i]!=s[j]) return 0;
           i++;
           j--;
        }
        return 1;
    }
    void solve(vector<vector<string>> &ans, string &s, int index, vector<string> t){
        if(index==s.size()){
            ans.push_back(t);
            return;
        }

        string str="";
        for(int i=index; i<s.size(); i++){
            str += s[i];
            if(isPalindrome(str)){
                t.push_back(str);
                solve(ans, s, i+1, t);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        solve(ans, s, 0, t);
        return ans;
    }
};