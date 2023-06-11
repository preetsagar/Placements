// Link - https://practice.geeksforgeeks.org/problems/prime-factors5052/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
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
	    for(int i=2; i<=N; i++){
	        if(prime[i] && N%i==0) ans.push_back(i);
	    }
	    return ans;
	}
};