// Link - https://www.interviewbit.com/problems/nearest-smaller-element/

#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans;
    stack<int> stk;
    for(int i:A){
        while(!stk.empty() && stk.top()>=i) stk.pop();
        if(stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        
        stk.push(i);
    }
    return ans;
}
