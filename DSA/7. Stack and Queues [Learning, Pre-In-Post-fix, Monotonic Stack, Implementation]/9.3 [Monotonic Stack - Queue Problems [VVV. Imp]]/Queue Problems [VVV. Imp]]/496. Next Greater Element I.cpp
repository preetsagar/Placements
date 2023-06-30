// Link - https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> t;
        unordered_map<int, int> m;
        for(int i=nums2.size()-1; i>=0; i--){
            if(t.empty()){
                m[nums2[i]] = -1;
                t.push(nums2[i]);
            }
            else{
                while(!t.empty() && nums2[i]>=t.top()){
                    t.pop();
                }
                if(t.empty()){
                    m[nums2[i]] = -1;
                    t.push(nums2[i]);
                }
                else{
                    m[nums2[i]] = t.top();
                    t.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        for(int i:nums1){
            ans.push_back(m[i]);
        }
        return ans;
    }
};