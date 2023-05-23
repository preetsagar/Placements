// Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &weights, int weight)
    {
        int day = 0;
        int temp = 0;
        int i = 0;
        while (i < weights.size())
        {
            temp = 0;
            while (i < weights.size() && temp <= weight)
            {
                temp += weights[i];
                i++;
            }
            if (temp > weight)
            {
                i--;
            }
            day++;
        }
        return day;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 1, r = 0;
        for (int i : weights)
        {
            r += i;
            l = max(l, i);
        }
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int day = solve(weights, mid);
            // this function returns not of days required to ship all weights
            // with the maximum shipping capasity of conveyor belt as mid;
            if (day <= days)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            cout << mid << " " << day << endl;
        }
        return ans;
    }
};