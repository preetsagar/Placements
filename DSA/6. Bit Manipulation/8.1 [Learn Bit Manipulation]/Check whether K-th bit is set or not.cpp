// Link - https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        if(n & (1<<k)) return 1;
        return 0;
    }
};

