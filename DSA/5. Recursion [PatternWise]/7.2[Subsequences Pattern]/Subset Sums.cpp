// Link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int>&arr, int N, int i, int sum, vector<int> &ans){
        if(i==N){
            ans.push_back(sum);
            return;
        }
        
        // not take
        solve(arr, N, i+1, sum, ans);
        
        // Take
        solve(arr, N, i+1, sum+arr[i], ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr, N, 0, 0, ans);
        return ans;
    }
};