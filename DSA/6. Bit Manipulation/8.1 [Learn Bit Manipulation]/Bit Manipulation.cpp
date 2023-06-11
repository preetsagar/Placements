// Link - https://practice.geeksforgeeks.org/problems/bit-manipulation-1666686020/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        i = 1<<(i-1);
        cout<< ((num&i) ? 1 : 0)<<" ";
        cout<< (num|i)<<" ";
        cout<< (num&(~i));
    }
};