// Link - https://practice.geeksforgeeks.org/problems/aggressive-cows/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPlacable(vector<int> &stalls, int d, int k)
    {
        int count = 1;
        int last = 0;
        for (int i = 1; i < stalls.size(); i++)
        {
            if ((stalls[i] - stalls[last]) >= d)
            {
                count++;
                last = i;
            }
        }
        return count >= k;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int l = 1, r = 0;
        for (int i : stalls)
        {
            r = max(r, i);
        }
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // int t = 0;
            bool t = isPlacable(stalls, mid, k);
            if (t)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        int d = INT_MAX;
        if (ans != -1)
        {
            int last = 0;
            for (int i = 1; i < stalls.size(); i++)
            {
                if (stalls[i] - stalls[last] >= ans)
                {
                    d = min(d, stalls[i] - stalls[last]);
                    last = i;
                }
            }
        }
        return ans == -1 ? -1 : d;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends