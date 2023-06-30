// Link - https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        vector<int> prevSmall(n,0);
        vector<int> nextSmall(n,0);
        stack<int> stk;
        for(int i=0; i<n; i++){
            if(stk.empty()) prevSmall[i] = -1;
            else{
                while(!stk.empty() && arr[stk.top()]>arr[i]) stk.pop();
                if(stk.empty()) prevSmall[i] = -1;
                else  prevSmall[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=n-1; i>=0; i--){
            if(stk.empty()) nextSmall[i] = -1;
            else{
                while(!stk.empty() && arr[stk.top()]>=arr[i]) stk.pop();
                if(stk.empty()) nextSmall[i] = -1;
                else  nextSmall[i] = stk.top();
            }
            stk.push(i);
        }

        
        for(int i=0; i<n; i++){
            int prev = prevSmall[i]==-1 ? i : i - prevSmall[i]-1;
            int next = nextSmall[i]==-1 ? (n-i-1) : nextSmall[i]-i-1;
            ans = (ans + 1ll*(next+1)*(prev+1)*(arr[i]))%m;
        }
        return ans;
    }
};