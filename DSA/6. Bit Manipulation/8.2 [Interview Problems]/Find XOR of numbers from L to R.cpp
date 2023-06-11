// Link - https://practice.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int xorTillN(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
    }
    int findXOR(int l, int r) {
        return xorTillN(l)^xorTillN(r)^l;
    }
};