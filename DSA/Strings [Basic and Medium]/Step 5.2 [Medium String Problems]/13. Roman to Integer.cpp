// Link - https://leetcode.com/problems/roman-to-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getValue(char ch)
    {
        if (ch == 'I')
        {
            return 1;
        }
        if (ch == 'V')
        {
            return 5;
        }
        if (ch == 'X')
        {
            return 10;
        }
        if (ch == 'L')
        {
            return 50;
        }
        if (ch == 'C')
        {
            return 100;
        }
        if (ch == 'D')
        {
            return 500;
        }
        if (ch == 'M')
        {
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s)
    {
        int ans = 0;
        int i = s.size() - 1;
        ans += getValue(s[i--]);

        while (i >= 0)
        {
            if (getValue(s[i]) >= getValue(s[i + 1]))
            {
                ans += getValue(s[i]);
            }
            else
            {
                ans -= getValue(s[i]);
            }

            i--;
        }
        return ans;
    }
};