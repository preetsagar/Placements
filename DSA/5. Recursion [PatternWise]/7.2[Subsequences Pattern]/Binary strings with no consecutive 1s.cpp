// Link - https://www.codingninjas.com/codestudio/problems/binary-strings-with-no-consecutive-1s_893001

#include <bits/stdc++.h>
using namespace std;

void solve(int &k, int n, vector<string> &ans, string s){
    if(k==n){
        ans.push_back(s);
        return;
    }
    if(n==0 || s[n-1]=='0'){
        solve(k, n+1, ans, s+'0');
        solve(k, n+1, ans, s+'1');
    }
    else{
        solve(k, n+1, ans, s+'0');
    }
}


vector<string> generateString(int k) {
    // Write your code here.
    vector<string> ans;
    solve(k,0, ans,"");
    return ans;
}