// Link - https://practice.geeksforgeeks.org/problems/swap-two-numbers3844/1
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    pair<int, int> get(int a, int b){
        pair<int, int> ans;
        a = a^b;
        b = a^b;
        a = a^b;
        
        ans.first = a;
        ans.second = b;
        return ans;
    }
};