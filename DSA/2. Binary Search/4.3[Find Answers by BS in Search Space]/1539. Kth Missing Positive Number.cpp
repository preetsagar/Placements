// Link -

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // Method 1 2 pointer Approach
        // int t=1;
        // int i=0;
        // while(k && i<arr.size()){
        //     if(arr[i]==t){
        //         t++;
        //         i++;
        //     }
        //     else{
        //         t++;
        //         k--;
        //     }
        // }
        // if(k){
        //     t += k;
        // }
        // return t-1;

        // Method 2 Binary search
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            int missingCount = arr[mid] - (mid + 1);
            if (k > missingCount)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (r == -1)
        {
            return k;
        }
        else
        {
            return arr[r] + (k - (arr[r] - r - 1));
        }
    }
};