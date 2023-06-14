// Link - https://practice.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string pre) {
        stack<string> post;
        for(int i=pre.size()-1; i>=0; i--){
            if((pre[i]>='A' && pre[i]<='Z') || (pre[i]>='a' && pre[i]<='z') || (pre[i]>='0' && pre[i]<='9')){ 
                string t = "";
                t += pre[i];
                post.push(t);
            }
            else{
                string a,b,res;
                a = post.top(); post.pop();
                b = post.top(); post.pop();
                // note
                res = a + b + pre[i];
                post.push(res);
            }
        }
        return post.top();
    }
};