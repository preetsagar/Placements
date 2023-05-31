// Link - https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *even = head, *odd = head->next, *temp = head->next;
        while (odd && odd->next)
        {
            even->next = odd->next;
            even = even->next;
            if (even)
            {
                odd->next = even->next;
                odd = odd->next;
            }
        }
        even->next = temp;
        return head;
    }
};