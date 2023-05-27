// Link - https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *fast = node->next, *slow = node;

        // O(N) SOLUTION

        // while(fast->next != NULL){
        //     slow->val = fast->val;
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        // slow->val = fast->val;
        // slow->next = NULL;

        // O(1) SOLUTION

        slow->val = fast->val;
        slow->next = fast->next;
    }
};