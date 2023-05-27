// Link -

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int d)
    {
        int ans = 0;
        for (int i : nums)
        {
            if (i % d == 0)
            {
                ans += (i / d);
            }
            else
            {
                ans += ((i / d) + 1);
            }
        }
        return ans;
    }
    int smallestDivisor(vector<int> &nums, int th)
    {
        int l = 1, r = 0;
        int ans = -1;
        for (int i : nums)
        {
            r = max(r, i);
        }
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int sum = solve(nums, mid);
            if (sum <= th)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            // cout<<mid<<" "<<sum<<endl;
        }
        return ans;
    }
};