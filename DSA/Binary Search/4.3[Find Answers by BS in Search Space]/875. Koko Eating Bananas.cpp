// Link - https://leetcode.com/problems/koko-eating-bananas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> poles, int k)
    {
        int i = 0;
        long long hour = 0;
        while (i < poles.size())
        {
            if (poles[i] % k == 0)
            {
                hour += (long long)(poles[i] / k);
            }
            else if (poles[i] < k)
            {
                hour++;
            }
            else
            {
                hour += ((poles[i] / k) + 1);
            }
            i++;
        }
        return hour;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = 0;
        for (int pile : piles)
        {
            r = max(r, pile);
        }
        // cout<<l<<" "<<r<<endl;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long long hours = solve(piles, mid);
            if (hours <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            // cout<<mid<<" "<<hours<<endl;
        }
        return ans;
    }
};
