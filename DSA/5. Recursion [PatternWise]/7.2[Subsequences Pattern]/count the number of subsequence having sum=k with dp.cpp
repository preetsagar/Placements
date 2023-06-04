// Link - https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9+7;
vector<vector<int>> dp;
int solve(int arr[], int &n , int target, int index, int sum){
    
    if(sum > target){
        return 0;
    }
    
    if(index==n){
        if(sum==target){
            return 1;
        }
        return 0;
    }
    
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    
    // Take
    int choice1 = solve(arr, n, target, index+1, sum+arr[index]);
    
    // Not Take
    int choice2 = solve(arr, n, target, index+1, sum);
    
    return dp[index][sum] = (choice1 + choice2)%mod;
}

int perfectSum(int arr[], int n, int sum)
{
    // Note sum+1, or you will get random values in ans bacause dp[i][sum] will give random values
    dp.resize(n, vector<int>(sum+1, -1));
    return solve(arr, n, sum, 0, 0);
}