// Link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller(heights.size(),heights.size());
        stack<int> stk;
        for(int i=heights.size()-1; i>=0; i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            if(!stk.empty()) nextSmaller[i] = stk.top();
            stk.push(i);
        }

        vector<int> prevSmaller(heights.size(), -1);
        while(!stk.empty()) stk.pop();
        for(int i=0; i<heights.size(); i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            if(!stk.empty()) prevSmaller[i] = stk.top();
            stk.push(i);
        }

        int ans=0;
        for(int i=0; i<heights.size(); i++){
            // cout<<"("<<prevSmaller[i]<<","<<nextSmaller[i]<<") ";
            ans = max(ans, ((nextSmaller[i]-prevSmaller[i]-1)*heights[i]));
        }
        return ans;
    }
};