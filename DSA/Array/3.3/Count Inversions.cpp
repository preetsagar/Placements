
// Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void merge(long long arr[], int l, int mid, int r, long long int &count)
    {
        long long int i = l;
        long long int j = mid + 1;
        long long temp[(r - l) + 1];
        long long int k = 0;

        while (i <= mid && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                count += (mid - i + 1);
            }
        }
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while (j <= r)
        {
            temp[k++] = arr[j++];
        }
        for (int t = 0; t < k; t++)
        {
            arr[l++] = temp[t];
        }
    }
    void mergeSort(long long arr[], long long l, long long r, long long int &count)
    {
        if (l >= r)
        {
            return;
        }
        long long int mid = (l + r) / 2;
        mergeSort(arr, l, mid, count);
        mergeSort(arr, mid + 1, r, count);
        merge(arr, l, mid, r, count);
    }

    long long int inversionCount(long long arr[], long long N)
    {
        long long int count = 0;
        mergeSort(arr, 0, N - 1, count);
        return count;
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends