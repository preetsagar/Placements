// Question Link
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int i, int x)
    {
        if (i == nums.size())
        {
            return x;
        }
        int taken = solve(nums, i + 1, x ^ nums[i]);
        int notTaken = solve(nums, i + 1, x);
        return taken + notTaken;
    }
    int subsetXORSum(vector<int> &nums)
    {
        int ans = solve(nums, 0, 0);
        return ans;
    }
};