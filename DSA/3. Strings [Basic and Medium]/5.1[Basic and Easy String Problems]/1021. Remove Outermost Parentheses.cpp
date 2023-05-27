// Link - https://leetcode.com/problems/remove-outermost-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> stk;

        int i = 0;
        string ans = "";
        while (i < s.size())
        {
            if (stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                if (s[i] == '(')
                {
                    stk.push(s[i]);
                    ans += '(';
                }
                else
                {
                    stk.pop();
                    if (!stk.empty())
                    {
                        ans += ')';
                    }
                }
            }
            i++;
        }
        return ans;
    }
};