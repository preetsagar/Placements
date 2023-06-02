// Link - https://leetcode.com/problems/count-good-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int m = 1e9 + 7;
    int pow(long long n, long long k)
    {
        if (k == 0)
        {
            return 1;
        }
        if (k % 2 == 0)
        {
            return pow((n * n) % m, k / 2);
        }
        return (n * pow(n, k - 1) * 1ll) % m;
    }
    int countGoodNumbers(long long n)
    {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long t1 = pow(5, even);
        long long t2 = pow(4, odd);
        return (t1 * 1ll * t2) % m;
    }
};