// Link - https://leetcode.com/problems/min-stack/submissions/969356104/

#include <bits/stdc++.h>
using namespace std;


// Method 1
class MinStack {
public:
    stack<long long> stk;
    long long min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            min = val;
            stk.push(val);
        }
        else{
            if(val < min){
                long long t = 2*(1ll*val) - min;
                stk.push(t);
                min = val;
            }
            else{
                stk.push(val);
            }
        }
    }
    
    void pop() {
        long long top = stk.top();
        if(top < min){
            // means this is the current min but while inserting it was modified
            // so update min to prev min and then pop
            long long prevMin = 2*(1ll * min) - top;
            stk.pop();
            min = prevMin;
            if(stk.empty()){
                min = INT_MAX;
            }
        }
        else{
            // current top is not the min element
            stk.pop();
        }
    }
    
    int top() {
        if(stk.top() < min){
            return min;
        }
        return stk.top();
    }
    
    int getMin() {
        return min;
    }
};


// Method 2
class MinStack {
public:
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        }
        else{
            int mn = min(val, stk.top().second);
            stk.push({val, mn});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        if(stk.empty()) return -1;
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};