// Link - https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, char> m;
        unordered_map<char, char> taken;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) == m.end() && taken.find(t[i]) == taken.end())
            {
                m[s[i]] = t[i];
                taken[t[i]] = s[i];
            }
            else
            {
                if (m.find(s[i]) != m.end() && m[s[i]] != t[i])
                {
                    return false;
                }
                if (taken.find(t[i]) != taken.end() && taken[t[i]] != s[i])
                {
                    return false;
                }
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (t[i] != m[s[i]])
            {
                return false;
            }
        }
        return true;
    }
};