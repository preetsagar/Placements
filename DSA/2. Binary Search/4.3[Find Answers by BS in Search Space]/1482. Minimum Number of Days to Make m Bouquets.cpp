// Link - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &bloomDay, int k, int day)
    {
        int k_count = 0, m_count = 0;
        int i = 0;
        while (i < bloomDay.size())
        {
            if (bloomDay[i] <= day)
            {
                while (i < bloomDay.size() and bloomDay[i] <= day && k_count < k)
                {
                    k_count++;
                    i++;
                }
                if (k_count == k)
                {
                    m_count++;
                }
                k_count = 0;
            }
            else
            {
                i++;
            }
        }
        return m_count;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int l = 1, r;
        for (int i : bloomDay)
        {
            r = max(r, i);
        }
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int m_count = solve(bloomDay, k, mid);
            if (m_count >= m)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};