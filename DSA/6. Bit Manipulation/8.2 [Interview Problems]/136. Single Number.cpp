// Link - https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto num:nums){
            x ^= num;
        }
        return x;
    }
};