// Link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int deep = 0;

        int i = 0;
        int ans = 0;
        while (i < s.size())
        {
            if (s[i] == '(')
            {
                deep++;
                ans = max(ans, deep);
            }
            else if (s[i] == ')')
            {
                deep--;
            }

            i++;
        }

        return ans;
    }
};