// Link - https://practice.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre) {
        stack<string> infix;
        for(int i=pre.size()-1; i>=0; i--){
            if((pre[i]>='A' && pre[i]<='Z') || (pre[i]>='a' && pre[i]<='z') || (pre[i]>='0' && pre[i]<='9')){ 
                string t = "";
                t += pre[i];
                infix.push(t);
            }
            else{
                string a,b,res;
                a = infix.top(); infix.pop();
                b = infix.top(); infix.pop();
                // note
                res = "(" + a + pre[i] + b + ')';
                infix.push(res);
            }
        }
        return infix.top();
    }
};