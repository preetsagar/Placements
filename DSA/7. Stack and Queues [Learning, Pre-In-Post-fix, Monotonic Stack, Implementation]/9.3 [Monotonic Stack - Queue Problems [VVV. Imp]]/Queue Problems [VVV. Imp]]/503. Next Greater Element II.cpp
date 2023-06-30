// Link - https://leetcode.com/problems/next-greater-element-ii/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        vector<int> ans(N, -1);
        stack<int> stk;
        for(int i=2*N-1; i>=0; i--){
            while(!stk.empty() && stk.top()<=arr[i%N])  stk.pop();
            if(i<N){
                if(!stk.empty())  ans[i] = stk.top();
            }
            stk.push(arr[i%N]);
        }
        return ans;
    }
};