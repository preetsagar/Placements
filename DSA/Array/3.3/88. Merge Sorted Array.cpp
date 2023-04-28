// Link - https://leetcode.com/problems/merge-sorted-array/description/
// Variation 1

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int k = nums1.size() - 1;
        int i = m - 1;
        int j = n - 1;

        // start from the back and start putting max element

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        while (i >= 0)
        {
            nums1[k--] = nums1[i--];
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

// Link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?company[]=Synopsys&company[]=Synopsys&page=1&query=company[]Synopsyspage1company[]Synopsys
// Variation 2

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = n - 1, j = 0;
        while (i >= 0 and j < m)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
/*
1 3 (2 0)

(7 5) 6 8 9

1 2 1

2 3 4


*/

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends