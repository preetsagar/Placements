// Link - https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages.
    int solve(int A[], int N, int M, int page)
    {
        int count = 1;
        int temp = 0;
        for (int i = 0; i < N; i++)
        {
            temp += A[i];
            if (temp > page)
            {
                count++;
                temp = A[i];
            }
        }
        return count;
    }
    int findPages(int A[], int N, int M)
    {
        int l = INT_MIN, r = 0;
        int ans = -1;
        if (M > N)
        {
            return -1;
        }
        for (int i = 0; i < N; i++)
        {
            r += A[i];
            l = max(l, A[i]);
        }
        while (l <= r)
        {
            // Here mid denotes the maximum no of pages that can be allocated to any student
            int mid = (l + r) / 2;
            int t = solve(A, N, M, mid);
            if (t <= M)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            // cout<<"("<<mid<<","<<t<<") ";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends