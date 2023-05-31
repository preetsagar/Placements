// Link - https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return 1;
        }

        // Find the MID Pointer
        ListNode *fast = head, *slow = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
        }

        // Reverse the Linked List after the mid
        ListNode *reverseHead = NULL;
        while (slow)
        {
            ListNode *next = slow->next;
            slow->next = reverseHead;
            reverseHead = slow;
            slow = next;
        }

        // Check for Palindrome
        while (head && reverseHead)
        {
            if (head->val != reverseHead->val)
            {
                return 0;
            }
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return 1;
    }
};