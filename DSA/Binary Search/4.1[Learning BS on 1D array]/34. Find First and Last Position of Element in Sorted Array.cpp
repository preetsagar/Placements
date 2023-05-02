// Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);

        int l = 0, r = nums.size() - 1;
        int left_index = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                left_index = mid;
            }
            if (nums[mid] >= target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        int right_index = -1;
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                right_index = mid;
            }
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        ans[0] = left_index;
        ans[1] = right_index;
        return ans;
    }
};