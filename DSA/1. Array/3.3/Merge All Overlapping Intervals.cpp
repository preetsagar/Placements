
// Link - https://www.codingninjas.com/codestudio/problems/merge-all-overlapping-intervals_6783452?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    ans.push_back(arr.front());

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        else
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}