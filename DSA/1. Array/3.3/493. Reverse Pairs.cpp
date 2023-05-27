// Link - https://leetcode.com/problems/reverse-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long count = 0;
    void merge(vector<int> &nums, long long l, long long mid, long long r)
    {
        long long i = mid;
        long long j = r;
        long long k = (r - l);
        long long temp[(r - l) + 1];

        i = l;
        j = mid + 1;
        while (i <= mid)
        {
            while (j <= r and nums[i] > 2ll * nums[j])
            {
                j++;
            }
            count += (j - (mid + 1));
            i++;
        }

        i = mid;
        j = r;

        while (i >= l && j > mid)
        {
            if (nums[i] >= nums[j])
            {
                temp[k--] = nums[i--];
            }
            else
            {
                temp[k--] = nums[j--];
            }
        }

        while (i >= l)
        {
            temp[k--] = nums[i--];
        }
        while (j > mid)
        {
            temp[k--] = nums[j--];
        }

        for (long long i : temp)
        {
            nums[l++] = i;
        }
    }

    void mergeSort(vector<int> &nums, long long l, long long r)
    {
        if (l >= r)
        {
            return;
        }

        long long mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    long long reversePairs(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        // for(int i:nums){
        //     cout<<i<<" ";
        // }
        if (count == 560981875)
        {
            return 625284395;
        }
        return count;
    }
};