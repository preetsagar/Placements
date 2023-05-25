// Link - https://leetcode.com/problems/valid-anagram/description/https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string a, string b)
    {
        // WRONG METHOD XOR
        // int x=0;
        // for(auto ch: s){
        //     x ^= (ch-'ch');
        // }

        // for(auto ch: t){
        //     x ^= (ch-'ch');
        // }

        // if(x==0){
        //     return 1;
        // }
        // return 0;

        if (a.size() != b.size())
        {
            return 0;
        }

        unordered_map<char, int> m;
        for (int i = 0; i < a.size(); i++)
        {
            m[a[i]]++;
            m[b[i]]--;
        }

        for (auto i : m)
        {
            if (i.second != 0)
            {
                return 0;
            }
        }
        return 1;
    }
};