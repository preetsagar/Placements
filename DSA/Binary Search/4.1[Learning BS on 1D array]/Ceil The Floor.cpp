// Link - https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1

//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{

    sort(arr, arr + n);

    // FLOOR
    int f = -1;
    int l = 0, r = n - 1;
    if (arr[0] <= x)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == x)
            {
                f = arr[mid];
                break;
            }
            else if (arr[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        f = f != -1 ? f : arr[r];
    }

    // CEIL
    int c = -1;
    l = 0, r = n - 1;
    if (arr[r] >= x)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == x)
            {
                c = arr[mid];
                break;
            }
            else if (arr[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        c = c != -1 ? c : arr[l];
    }
    return {f, c};
}