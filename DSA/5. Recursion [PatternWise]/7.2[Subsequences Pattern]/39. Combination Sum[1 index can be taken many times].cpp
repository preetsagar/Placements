// Link - https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int> &candidate, vector<int> ds, int &target, int index, int sum){
        if(sum > target){
            return;
        }
        if(index==candidate.size()){
            if(sum==target){
                ans.push_back(ds);
            }
            return;
        }

        // did not take current index for calculation sum
        solve(ans, candidate, ds, target, index+1, sum);

        // took current index for calculating sum and stayed on the same index
        ds.push_back(candidate[index]);
        solve(ans, candidate, ds, target, index, sum+candidate[index]);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans, candidates, ds, target, 0, 0);
        return ans;
    }
};