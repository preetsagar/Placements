// Link - https://leetcode.com/problems/count-primes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<int> prime(n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for(int i=2; i<n; i++){
            if(prime[i]){
                for(int j=2*i; j<n; j+=i){
                    prime[j] = 0;
                }
            }
        }
        int count=0;
        for(auto i:prime){
            if(i) count++;
        }
        return count;
    }
};