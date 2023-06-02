// Link - https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m = 1e9 + 7;
    // You need to complete this fucntion
    long long Pow(long long x, int n)
    {
        // NOTE
        x = x % m;
        if (n == 0)
        {
            return 1;
        }
        if (n % 2 == 0)
        {
            return (Pow(x * x, n / 2) * 1ll) % m;
        }
        return (x * (Pow(x, n - 1) % m)) % m;
    }

    long long power(int N, int R)
    {
        long long ans;
        ans = Pow(N, R);
        return ans;
    }
};