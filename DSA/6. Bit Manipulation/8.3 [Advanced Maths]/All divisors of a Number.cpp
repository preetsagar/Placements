// Link - https://practice.geeksforgeeks.org/problems/all-divisors-of-a-number/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for(int i=1; i*i <=n; i++){
            if(n%i==0) ans.push_back(i);
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
        for(auto i=ans.end()-1; i>=ans.begin(); i--){
            int t = *i;
            if(n/t != t){
                cout<<n/t<<" ";
            }
        }
    }
};