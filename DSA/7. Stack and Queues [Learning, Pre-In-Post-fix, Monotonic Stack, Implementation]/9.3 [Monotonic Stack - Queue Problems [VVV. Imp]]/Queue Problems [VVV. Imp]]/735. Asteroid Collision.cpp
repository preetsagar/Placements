// Link - https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> stk;
        for(int i:a){
            if(stk.empty()) stk.push(i);
            else if(stk.top()*i > 0) stk.push(i);
            else{
                if(stk.top()<0){
                    stk.push(i);
                    continue;
                }
                int t = i;
                while(!stk.empty() && abs(stk.top()) < abs(t) && stk.top()*i < 0){
                    stk.pop();
                }
                if(stk.empty()) stk.push(t);
                else if(stk.top()*i > 0) stk.push(i);
                else if(abs(stk.top())==abs(t) && stk.top()*i < 0) stk.pop();
                // else khud destroy ho jayega
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};