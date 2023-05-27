// Link - https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long int atmostKSubstringCount(string s, int k)
    {
        int l = 0, r = 0;
        int distCount = 0;
        int freq[26] = {0};
        long long int ans = 0;

        while (r < s.size())
        {
            freq[s[r] - 'a']++;
            if (freq[s[r] - 'a'] == 1)
            {
                distCount++;
            }
            r++;

            while (distCount > k)
            {
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0)
                {
                    distCount--;
                }
                l++;
            }
            ans += (r - l);
        }
        return ans;
    }

    long long int substrCount(string s, int k)
    {
        return atmostKSubstringCount(s, k) - atmostKSubstringCount(s, k - 1);
    }
};

// umeaylnlfd
// 2

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.substrCount(s, k) << endl;
    }
}
// } Driver Code Ends