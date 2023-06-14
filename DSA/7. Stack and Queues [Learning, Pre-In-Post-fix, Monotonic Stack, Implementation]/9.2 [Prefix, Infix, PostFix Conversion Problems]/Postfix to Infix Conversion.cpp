// Link - https://practice.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

#include <bits/stdc++.h>
using namespace std;

string postToInfix(string exp) {
    stack<string> infix;
    for(char ch:exp){
        if(isalpha(ch)){
            string t="";
            t += ch;
            infix.push(t);
        }
        else{
            string a,b;
            b = infix.top(); infix.pop();
            a = infix.top(); infix.pop();
            // note (storing in res was giving tle)
            infix.push('(' + a + ch + b + ')');
        }
    }
    return infix.top();
}