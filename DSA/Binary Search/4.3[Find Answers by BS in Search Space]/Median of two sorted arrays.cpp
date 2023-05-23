// Link - https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // M1- mergesort method while merging

        // M2
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        if (n2 == 0)
        {
            return n1 % 2 == 0 ? (nums1[n1 / 2] + nums1[((n1 / 2) - 1)]) / 2.0 : nums1[n1 / 2];
        }
        if (n1 == 0)
        {
            return n2 % 2 == 0 ? (nums2[n2 / 2] + nums2[((n2 / 2) - 1)]) / 2.0 : nums2[n2 / 2];
        }

        int mid = (n1 + n2 + 1) / 2;
        int l = 0, r = min(n1, mid);
        int cut1, cut2;

        while (l <= r)
        {
            cut1 = (l + r) / 2;
            cut2 = mid - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                r = cut1 - 1;
            }
            else
            {
                l = cut1 + 1;
            }
        }
        return 0;
    }
};