// Link - https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int maxPowerof2(int n){
        int x=0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
    }
    
    int countSetBits(int n){
        if(n==0 || n==1) return n;
        
        int x = maxPowerof2(n);
        int perfectSetCount = x * (1<<x-1);
        int remainingNumber = n - (1<<x) + 1;
        int count = perfectSetCount + remainingNumber;
        int afterMsbRemoval = n-(1<<x);
        return count + countSetBits(afterMsbRemoval);
    }
};