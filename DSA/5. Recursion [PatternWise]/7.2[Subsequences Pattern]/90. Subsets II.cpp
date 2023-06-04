// Link - https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> ds, int index){
        if(index==nums.size())  return;

        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i-1]==nums[i]) continue;

            ds.push_back(nums[i]);
            ans.push_back(ds);
            solve(ans, nums, ds, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        sort(nums.begin(), nums.end());
        ans.push_back(t);
        solve(ans, nums, t, 0);
        return ans;
    }
};