// Link - https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Method 1 [Using Recursion]
    void solve(vector<int> &nums, int i, vector<int> t, vector<vector<int>> &ans){
        if(i==0){
            ans.push_back(t);
            return;
        }
        solve(nums, i-1, t, ans);
        t.push_back(nums[i-1]);
        solve(nums, i-1, t, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        solve(nums, nums.size(), t, ans);
        return ans;
    }


    // Method 2 Using [using bit]
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= pow(2, nums.size());
        int m= log2(n-1)+1;
        for(int i=0; i<n; i++){
            vector<int> t;
            for(int j=0; j<m; j++){
                if(i&(1<<j)){
                    t.push_back(nums[j]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};