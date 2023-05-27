// Link - https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

// Mwthod 1

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int r = row * col - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int i = mid / col;
            int j = mid % col;
            if (matrix[i][j] == target)
            {
                return 1;
            }
            else if (matrix[i][j] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return 0;
    }
};

// Method 2

class Solution
{
public:
    int matSearch(vector<vector<int>> &mat, int N, int M, int X)
    {
        // your code here
        int i = 0, j = M - 1;
        while (j >= 0 and i < N)
        {
            if (mat[i][j] == X)
            {
                return true;
            }
            else if (mat[i][j] < X)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};