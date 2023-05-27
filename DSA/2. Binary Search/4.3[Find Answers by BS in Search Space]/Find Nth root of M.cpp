// Link - https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        long long int l = 1;
        long long int r = m;
        long long int ans = -1;
        while (l <= r)
        {
            long long int mid = (l + r) / 2;

            if (pow(mid, n) == m)
            {
                return mid;
            }
            else if (pow(mid, n) < m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
