// Link - https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int n=q.size();
        q.push(x);
        while(n--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!q.empty()){
            int t = q.front();
            q.pop();
            return t;
        }
        return -1;
    }
    
    int top() {
        if(!q.empty()) return q.front();
        return -1;
    }
    
    bool empty() {
        if(!q.empty()) return false;
        return true;
    }
};