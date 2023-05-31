// Link - https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || !k)
        {
            return head;
        }
        ListNode *temp = head, *t2;
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len++;
        }

        k = k % len;
        if (k == 0)
        {
            return head;
        }
        k = len - k;
        temp = head;
        while (--k)
        {
            temp = temp->next;
        }
        cout << temp->val;
        t2 = temp->next;
        temp->next = NULL;

        temp = t2;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;
        head = t2;

        return head;
    }
};