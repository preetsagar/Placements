// Link - https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(vector<int> &arr, int &k, int i, int x)
    {

        if (i == arr.size())
        {
            if (x == k)
            {
                return 1;
            }
            return 0;
        }

        int taken = solve(arr, k, i + 1, x ^ arr[i]);
        int notTaken = solve(arr, k, i + 1, x);
        return (taken + notTaken);
    }

    int subsetXOR(vector<int> arr, int N, int K)
    {
        // code here
        int ans;
        ans = solve(arr, K, 0, 0);
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
        int N;
        cin >> N;
        int K;
        cin >> K;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        Solution ob;
        cout << ob.subsetXOR(v, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends