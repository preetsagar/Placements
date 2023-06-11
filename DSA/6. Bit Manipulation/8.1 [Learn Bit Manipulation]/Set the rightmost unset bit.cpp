// Link - https://practice.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBit(int N)
    {
        int t=N;
        int count=0;
        while(t){
            if(t&1) count++;
            else break;
            t = t>>1;
        }
        
        if((int)(log2(N)+1)==count) return N;
        return N|(1<<count);
    }
};