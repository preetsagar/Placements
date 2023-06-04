// Link - https://leetcode.com/problems/combination-sum-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
void solve(vector<vector<int>> &ans, vector<int> &arr, vector<int> ds, int index, int sum, int k){
        if(sum <0) return;

        if(k==0 || sum==0 || index==9){
            if(k==0 && sum==0)  ans.push_back(ds);
            return;
        }

        // taken
        ds.push_back(arr[index]);
        solve(ans, arr, ds, index+1, sum-arr[index], k-1);
        ds.pop_back();

        // not taken
        solve(ans, arr, ds, index+1, sum, k);
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> arr;
    for(int i=1; i<=9; i++){
        arr.push_back(i);
    }
    solve(ans, arr, ds, 0, n, k);
    return ans;
    }
};