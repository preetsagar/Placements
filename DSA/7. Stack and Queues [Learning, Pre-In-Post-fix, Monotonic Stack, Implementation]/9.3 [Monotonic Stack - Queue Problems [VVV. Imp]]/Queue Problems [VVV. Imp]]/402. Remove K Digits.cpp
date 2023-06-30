// Link - https://leetcode.com/problems/remove-k-digits/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for(char t:num){
            if(!k) stk.push(t);
            else if(stk.empty()) stk.push(t);
            else if(stk.top() > t){
                while(k && !stk.empty() && stk.top()>t){
                    stk.pop();
                    k--;
                }
                stk.push(t);
            }
            else stk.push(t);
        }
        string ans="";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        ans = ans.substr(k);
        reverse(ans.begin(), ans.end());
        cout<<ans;

        while(ans[0]=='0') ans = ans.substr(1);
        if(ans == "")   return "0";
        return ans;
    }
};