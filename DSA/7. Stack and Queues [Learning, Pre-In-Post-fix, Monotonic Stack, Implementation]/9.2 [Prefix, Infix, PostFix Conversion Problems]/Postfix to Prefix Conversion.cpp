// Link - https://practice.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> pre_exp;
        for(int i=0; i<post_exp.size(); i++){
            if((post_exp[i]>='A' && post_exp[i]<='Z') || (post_exp[i]>='a' && post_exp[i]<='z') || (post_exp[i]>='0' && post_exp[i]<='9')){ 
                string t = "";
                t += post_exp[i];
                pre_exp.push(t);
            }
            else{
                string a,b,res;
                b = pre_exp.top(); pre_exp.pop();
                a = pre_exp.top(); pre_exp.pop();
                // note
                res = post_exp[i] + a + b;
                pre_exp.push(res);
            }
        }
        return pre_exp.top();
    }
};