// Link - https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int lessThanEqualTo(vector<int>&nums, int t){
        int l=0, r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]<=t){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
    int pow(int n, int m){
        if(m==0){
            return 1;
        }

        if(m%2==0){
            return pow((1ll*n*n)%mod, m/2);
        }
        return (1ll*n*pow(n, m-1))%mod;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i=0;
        long long ans=0;
        while(i<nums.size()){
            int j=lessThanEqualTo(nums, target-nums[i]);
            if(i<=j){
                long long t = pow(2, j-i);
                t = t%mod;
                ans = (ans+t)%mod;
            }
            i++;
        }
        return ans;
    }
};