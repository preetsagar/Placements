// Link - https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;


// Method 1
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n, 0), right(n, 0);
        int mx;
        mx=INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, height[i]);
            left[i] = mx;
        }
        mx=INT_MIN;
        for(int i=n-1; i>=0; i--){
            mx = max(mx, height[i]);
            right[i] = mx;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};

// Method 2
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int left_max = INT_MIN, right_max= INT_MIN;
        int trapWater=0;
        while(l<=r){
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);
            if(left_max <= right_max){
                trapWater += (left_max - height[l]);
                l++;
            }
            else if(left_max > right_max){
                trapWater += (right_max-height[r]);
                r--;
            }
        }
        return trapWater;
    }
};