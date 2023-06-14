// Link - https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int priority(char t){
        if(t=='^') return 3;
        if(t=='*' || t=='/') return 2;
        if(t=='+' || t=='-') return 1;
        return 0;
    }
    
    bool isOperator(char t){
        if(t=='+' || t=='-' || t=='*' || t=='/' || t=='^') return 1;
        return 0;
    }
    
    string infixToPostfix(string s) {
        stack<string> postfix;
        stack<char> operatorr;
        
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){   
                operatorr.push(s[i]);
                i++;
            }
            else if(s[i]==')'){
                while(operatorr.top()!='('){
                    string a,b, op;
                    op = operatorr.top(); operatorr.pop();
                    b = postfix.top(); postfix.pop();
                    a = postfix.top(); postfix.pop();
                    string res = a + b + op;
                    postfix.push(res);
                }
                operatorr.pop();
                i++;
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                char t=s[i];
                string str = "";
                str += t;
                postfix.push(str);
                i++;
            }
            else{
                while(!operatorr.empty() && priority(s[i])<=priority(operatorr.top())){
                    string a,b, op;
                    op = operatorr.top(); operatorr.pop();
                    b = postfix.top(); postfix.pop();
                    a = postfix.top(); postfix.pop();
                    string res = a + b + op;
                    postfix.push(res);
                }
                operatorr.push(s[i]);
                i++;
            }
        }
        while(!operatorr.empty()){
            string a,b, op;
            op = operatorr.top(); operatorr.pop();
            b = postfix.top(); postfix.pop();
            a = postfix.top(); postfix.pop();
            string res = a + b + op;
            postfix.push(res);
        }
        return postfix.top();
    }
};