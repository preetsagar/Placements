// Link - https://leetcode.com/problems/power-of-two/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        return (n&(n-1))==0;
    }
};