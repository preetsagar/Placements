// Link  - https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int mid)
    {
        int count = 1;
        int t = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            t += nums[i];
            if (t > mid)
            {
                t = nums[i];
                count++;
            }
        }
        return count;
    }

    int splitArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
        {
            return -1;
        }

        int l = INT_MIN, r = 0;
        for (int i : nums)
        {
            r += i;
            l = max(l, i);
        }
        int ans = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            // Here mid denotes the maximum sum of any splited array;
            // Now check weather it is possible or not the split the array whose
            // maximum sum is mid;
            // IF a array can be splited into t array whose sum is <= mid

            // if t > k
            // it means it is not possible to split an array with maximum sum as mid
            // so increase the range i.e. l = mid+1;

            // if t <= k
            // it means by keeping the maximum sum as mid it is possible to split an array
            // now search for minimized mid to satisfied sum;
            int t = solve(nums, mid);
            if (t > k)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};
