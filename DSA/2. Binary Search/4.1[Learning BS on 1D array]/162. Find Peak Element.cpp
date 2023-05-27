// Link - https://leetcode.com/problems/find-peak-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }

        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid == 0 && nums[1] < nums[0])
            {
                return 0;
            }
            if (mid == nums.size() - 1 && nums[nums.size() - 1] > nums[nums.size() - 2])
            {
                return nums.size() - 1;
            }
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            {
                return mid;
            }

            if (nums[mid] < nums[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};