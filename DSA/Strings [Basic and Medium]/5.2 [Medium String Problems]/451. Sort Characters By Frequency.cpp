// Link - https://leetcode.com/problems/sort-characters-by-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class comperator
{
public:
    bool operator()(pair<int, char> a, pair<int, char> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

class Solution
{
public:
    string frequencySort(string s)
    {

        map<char, int> m;
        for (auto i : s)
        {
            m[i]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, comperator> pq;
        for (auto i : m)
        {
            pq.push({i.second, i.first});
        }

        string ans = "";
        while (!pq.empty())
        {
            pair<int, char> t = pq.top();
            pq.pop();
            cout << "(" << t.first << "," << t.second << ") ";
            while (t.first)
            {
                ans += t.second;
                t.first--;
            }
        }

        return ans;
    }
};