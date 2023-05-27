// Link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int l = 0, r = arr.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            if (arr[l] <= arr[mid])
            {
                // LEFT side is sorted
                if (target >= arr[l] && target <= arr[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                // RIGHT side is sorted
                if (target >= arr[mid] && target <= arr[r])
                {
                    // Righ side milega
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};