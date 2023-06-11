// Link - https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        long ds = abs(divisor);
        long dd = abs(dividend);

        int count=0;
        while(dd>=ds){
            int temp = 0;
            while((ds<<temp) <= dd){
                temp++;
            }
            dd = dd - (ds<<(temp-1));
            count += 1<<(temp-1);
        }

        if(dividend < 0 && divisor>0) return -1*count;
        if(dividend > 0 && divisor<0) return -1*count;
        return count;
    }
};