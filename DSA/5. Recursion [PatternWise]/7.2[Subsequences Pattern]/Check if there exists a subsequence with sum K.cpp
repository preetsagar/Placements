// Link - https://practice.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1?problemStatus=unsolved&page=1&sortBy=newest&query=problemStatusunsolvedpage1sortBynewest

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> dp;
    bool solve(vector<int> &arr, int k, int i, int sum){
        if(sum>k) return 0;
        
        if(i==arr.size()){
            if(sum==k) return 1;
            return 0;
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        
        if(solve(arr, k, i+1, sum+arr[i])) return dp[i][sum] = 1;
        if(solve(arr, k, i+1, sum)) return dp[i][sum] = 1;
        
        return dp[i][sum] = 0;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        dp.resize(n, vector<int>(k+1, -1));
        return solve(arr, k, 0, 0);
    }
};