// Link - https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        vector<long long int> ans;
        long long int x=0;
        for(long long int i=0; i<N; i++){
            x = x^Arr[i];
        }
        
        long long int n = log2(x);
        long long int a=0, b=0;
        for(int i=0; i<N; i++){
            if(Arr[i]&(1<<n)) a = a^Arr[i];
            else    b = b^Arr[i];
        }
        if(a < b){
            ans.push_back(b);
            ans.push_back(a);
        }
        else{
            ans.push_back(a);
            ans.push_back(b);
        }
        return ans;
    }
};