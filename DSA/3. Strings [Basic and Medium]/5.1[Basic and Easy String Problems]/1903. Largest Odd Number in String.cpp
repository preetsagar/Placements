// Link - https://leetcode.com/problems/largest-odd-number-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string ans = "";
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if (num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9')
            {
                ans = num.substr(0, i + 1);
                break;
            }
        }
        return ans;
    }
};