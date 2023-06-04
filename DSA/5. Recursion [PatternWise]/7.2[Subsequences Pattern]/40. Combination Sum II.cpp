// Link - https://leetcode.com/problems/combination-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<vector<int>>&ans, vector<int> &A, vector<int>ds, int &target, int sum, int index){
        if(sum>target) return;

        if(sum==target){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<A.size(); i++){
            if(i>index && A[i]==A[i-1]) continue;
            if(A[i]+sum > target) break;
            
            ds.push_back(A[i]);
            solve(ans, A, ds, target, sum+A[i], i+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        sort(A.begin(), A.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans, A, ds, B, 0, 0);
        return ans;
    }
};