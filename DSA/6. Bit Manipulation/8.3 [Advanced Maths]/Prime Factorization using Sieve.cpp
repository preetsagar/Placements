// Link - https://practice.geeksforgeeks.org/problems/prime-factorization-using-sieve/1

#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int N) {
        vector<int> prime(N+1, 1);
        prime[0] = 0;
        prime[1] = 0;
        for(int i=2; i<=N; i++){
            if(prime[i]){
                for(int j=2*i; j<=N; j+=i){
                    prime[j] = 0;
                }
            }
        }
        vector<int> ans;
        int i=2;
        while(N>1){
            if(N%i == 0){
                N = N/i;
                ans.push_back(i);
            }
            else{
                i++;
                while(i<N && prime[i]!=1){
                    i++;
                }
            }
        }
        return ans;
    }