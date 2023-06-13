// Link - https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char closingBracket(char t){
        if(t==')') return '(';
        if(t==']') return '[';
        if(t=='}') return '{';
        return ' ';
    }
    bool isValid(string s) {
        stack<char> stk;
        for(char i:s){
            if(stk.empty()) stk.push(i);
            else{
                if(i=='(' || i=='{' || i=='['){
                    stk.push(i);
                }
                else{
                    if(stk.top()==closingBracket(i)) stk.pop();
                    else return false;
                }
            }
        }
        return stk.empty();
    }
};