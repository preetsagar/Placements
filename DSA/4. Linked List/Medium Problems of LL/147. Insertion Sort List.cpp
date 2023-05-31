// Link - https://leetcode.com/problems/insertion-sort-list/description/

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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(100000);

        while (head)
        {
            ListNode *dummy_temp = dummy, *next = head->next;
            while (dummy_temp->next && dummy_temp->next->val < head->val)
            {
                dummy_temp = dummy_temp->next;
            }
            head->next = dummy_temp->next;
            dummy_temp->next = head;
            head = next;
        }
        return dummy->next;
    }
};