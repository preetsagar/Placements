// Link - https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */

    int leftMost(int arr[], int n, int x)
    {
        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }

    int rightMost(int arr[], int n, int x)
    {
        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }

    int count(int arr[], int n, int x)
    {
        int i = leftMost(arr, n, x);
        if (i >= 0 and i < n and arr[i] == x)
        {
            int j = rightMost(arr, n, x);

            return j - i + 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends