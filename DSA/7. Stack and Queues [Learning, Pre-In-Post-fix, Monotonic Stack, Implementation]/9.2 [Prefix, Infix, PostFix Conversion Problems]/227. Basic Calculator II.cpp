// Link - https://leetcode.com/problems/basic-calculator-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cal(int a, int b, char op){
        if(op=='+') return a+b;
        if(op=='-') return a-b;
        if(op=='*') return a*b;
        if(op=='/') return a/b;
        return 0;
    }

    int priority(char t){
        if(t=='*' || t=='/') return 2;
        return 1;
    }
    
    bool isOperand(char t){
        if(t-'0' >=0 && t-'0'<=9)   return 1;
        return 0;
    }

    int calculate(string s) {
        stack<char> op;
        stack<int> operand;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            else if(isOperand(s[i])){
                int num=0;
                while(isOperand(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                operand.push(num);
            }
            else{
                if(op.empty() || priority(op.top())<priority(s[i])){
                    op.push(s[i]);
                    i++;
                }
                else{
                    while(!op.empty() && op.top()!='(' && priority(op.top()) >= priority(s[i])){
                        char opp = op.top(); op.pop();
                        int a, b;
                        b = operand.top(); operand.pop();
                        a = operand.top(); operand.pop();
                        int result = cal(a, b, opp);
                        operand.push(result);
                    }
                    op.push(s[i]);
                    i++;
                }
            }
        }
        while(!op.empty()){
            char opp = op.top(); op.pop();
            int a, b;
            b = operand.top(); operand.pop();
            a = operand.top(); operand.pop();
            int result = cal(a, b, opp);
            operand.push(result);
        }
        return operand.top();
    }
};