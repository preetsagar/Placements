// Link - https://leetcode.com/problems/merge-sorted-array/description/

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
