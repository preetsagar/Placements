// Link - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dp;
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
    int solve(string &s, int index){
        if(index==s.size()) return 0;

        string str="";
        int minCost = INT_MAX;
        if(dp[index]!=-1) return dp[index];
        for(int i=index; i<s.size(); i++){
            str += s[i];
            if(isPalindrome(str)){
                int cost = 1 + solve(s, i+1);
                minCost = min(minCost, cost);
            }
        }
        return dp[index] = minCost;
    }
    int palindromicPartition(string s)
    {
        dp.resize(s.size(), -1);
        return solve(s, 0)-1;
    }
};