// Link - https://leetcode.com/problems/sort-list/description/

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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (left && right)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }
        if (left)
        {
            temp->next = left;
        }
        if (right)
        {
            temp->next = right;
        }
        return dummy->next;
    }

    ListNode *findMid(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *left, *mid, *right;
        left = head;
        mid = findMid(head);
        right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        left = merge(left, right);
        return left;
    }
};