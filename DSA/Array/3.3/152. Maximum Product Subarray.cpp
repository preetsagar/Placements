// Link - https://leetcode.com/problems/maximum-product-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = 1;
        int mini = 1;
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = maxi;
            maxi = max(nums[i], max(maxi * nums[i], mini * nums[i]));
            mini = min(nums[i], min(nums[i] * mini, temp * nums[i]));
            cout << maxi << " " << mini << endl;

            ans = max(ans, maxi);
        }
        return ans;
    }
};