// Link - https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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