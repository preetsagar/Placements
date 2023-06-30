// Link - https://leetcode.com/problems/sum-of-subarray-ranges/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m=1e9+7;
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        long long smallAns=0;
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
            smallAns = (smallAns + 1ll*(next+1)*(prev+1)*(arr[i]));
        }
        
        
        
        
        
        
        while(!stk.empty()) stk.pop();
        long long maxAns=0;
        vector<int> prevMax(n,0);
        vector<int> nextMax(n,0);
        for(int i=0; i<n; i++){
            if(stk.empty()) prevMax[i] = -1;
            else{
                while(!stk.empty() && arr[stk.top()]<arr[i]) stk.pop();
                if(stk.empty()) prevMax[i] = -1;
                else  prevMax[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=n-1; i>=0; i--){
            if(stk.empty()) nextMax[i] = -1;
            else{
                while(!stk.empty() && arr[stk.top()]<=arr[i]) stk.pop();
                if(stk.empty()) nextMax[i] = -1;
                else  nextMax[i] = stk.top();
            }
            stk.push(i);
        }

        
        for(int i=0; i<n; i++){
            int prev = prevMax[i]==-1 ? i : i - prevMax[i]-1;
            int next = nextMax[i]==-1 ? (n-i-1) : nextMax[i]-i-1;
            // cout<<"("<<prev<<" "<<next<<") ";
            maxAns = (maxAns + 1ll*(next+1)*(prev+1)*(arr[i]));
        }
        // cout<<smallAns<<" "<<maxAns;
        
        return maxAns-smallAns;
    }
};