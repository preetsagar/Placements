// Link -

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int freq[26] = {0};
            int distinct = 0;

            for (int j = i; j < s.size(); j++)
            {
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] == 1)
                {
                    distinct++;
                }
                if (distinct > 1)
                {

                    int mn = INT_MAX, mx = INT_MIN;
                    for (int k = 0; k < 26; k++)
                    {
                        mx = max(mx, freq[k]);
                        if (freq[k] != 0)
                            mn = min(mn, freq[k]);
                    }
                    ans += (mx - mn);
                }
            }
        }
        return ans;
    }
};