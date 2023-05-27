// https://leetcode.com/problems/xor-queries-of-a-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> preXOR(arr.size());
        int t = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            t = t ^ arr[i];
            preXOR[i] = t;
        }
        vector<int> ans;
        for (auto i : queries)
        {
            if (i[0] == 0)
            {
                ans.push_back(preXOR[i[1]]);
            }
            else
            {
                ans.push_back(preXOR[i[1]] ^ preXOR[i[0] - 1]);
            }
        }
        return ans;
    }
};