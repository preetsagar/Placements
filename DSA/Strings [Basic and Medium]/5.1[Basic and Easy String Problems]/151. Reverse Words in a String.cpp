// Link - https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // remove unwanted spaces

        // remove leading zeroes
        if (s[0] == ' ')
        {
            int i = 0;
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
            s = s.substr(i);
        }

        // remove trailing zeroes
        if (s[s.size() - 1] == ' ')
        {
            int i = s.size() - 1;
            int c = 0;
            while (i >= 0 && s[i] == ' ')
            {
                i--;
                c++;
            }
            s = s.substr(0, s.size() - c);
        }

        // remove in-between extra spaces
        string t = "";
        int i = 0;
        while (i < s.size())
        {
            if (s[i] != ' ')
            {
                t += s[i];
            }
            else
            {
                while (s[i] == ' ')
                {
                    i++;
                }
                t += ' ';
                i--;
            }
            i++;
        }
        s = t;

        reverse(s.begin(), s.end());
        int start = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
            if (i == n - 1)
            {
                reverse(s.begin() + start, s.end());
            }
        }

        return s;
    }
};
