// Link - https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double Pow(double x, int n){
        // Method 1
        // if(n==0){
        //     return 1;
        // }
        // return x*Pow(x, n-1);

        // Method 2
        if(n==0){
            return 1;
        }

        if(n%2==0){
            return Pow(x*x, n/2);
        }
        return x*Pow(x, n-1);
    }
    double myPow(double x, int n) {

        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;

        double ans;
        if(n<0){
            ans = Pow(x, abs(n));
            ans = 1/ans;

        }
        else{
            ans = Pow(x, n);
        }
        return ans;
    }
};