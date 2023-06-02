// Link - https://practice.geeksforgeeks.org/problems/reverse-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void addAtBottom(stack<int> &stk, int t){
        if(stk.size()==0){
            stk.push(t);
            return;
        }
        int top=stk.top(); stk.pop();
        addAtBottom(stk, t);
        stk.push(top);
    }
    void Reverse(stack<int> &stk){
        if(stk.size()<=1){
            return;
        }
        int t = stk.top(); stk.pop();
        Reverse(stk);
        addAtBottom(stk, t);
    }
};