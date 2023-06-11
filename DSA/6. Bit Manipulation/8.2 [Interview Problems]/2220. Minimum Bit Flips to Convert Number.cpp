// Link - https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        while(start && goal){
            if((start&1) != (goal&1)){
                count++;
            }
            start = start>>1;
            goal = goal>>1;
        }
        while(start){
            if((start&1)==1)
                count++;
            start = start>>1;
        }
        while(goal){
            if((goal&1)==1)
                count++;
            goal = goal>>1;
        }
        return count;
    }
};