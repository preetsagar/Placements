// Link - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x = x ^ arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            x = x ^ (i + 1);
        }

        int t = 1;
        x = x >> 1;
        while (x)
        {
            t = t << 1;
            x = x >> 1;
        }

        // cout<<"t = "<<t<<endl;
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & t)
            {
                a = a ^ arr[i];
            }
            else
            {
                b = b ^ arr[i];
            }
        }
        // cout<<a<<" "<<b<<endl;

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) & t)
            {
                a = a ^ (i + 1);
            }
            else
            {
                b = b ^ (i + 1);
            }
        }
        // cout<<a<<" "<<b<<endl;

        int *ans = new int[2];
        // now find weather a or b is missing in arr
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == a)
            {
                ans[0] = a;
                ans[1] = b;
                // return ans;
            }
            if (arr[i] == b)
            {
                ans[0] = b;
                ans[1] = a;
                // return ans;
            }
        }
        // cout<<ans[0]<<" "<<ans[1]<<endl;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Method 2 *********************************************************************************************************************

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int *ans = new int[2];

        for (int i = 0; i < n; i++)
        {
            int point = abs(arr[i]) - 1;
            if (arr[point] > 0)
            {
                arr[point] = arr[point] * -1;
            }
            else
            {
                ans[0] = point + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                ans[1] = (i + 1);
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends