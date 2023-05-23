// Link  - https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int lessThanOrWqualTo(vector<vector<int>> &matrix, int r, int c, int k)
    {
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            int l = 0;
            int r = c - 1;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (matrix[i][mid] <= k)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            count += (r + 1);
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int l = 1, r = 2000;
        int ans = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int t = lessThanOrWqualTo(matrix, R, C, mid);

            if (t >= (R * C + 1) / 2)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends