// Link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Deletes middle of linked list and returns head of the modified list
Node *deleteMid(Node *head)
{
    if (!head || !head->next)
    {
        return NULL;
    }

    Node *fast = head, *slow = head, *slow2 = head;
    while (fast->next)
    {
        slow2 = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
    }
    // cout<<slow->val;
    slow2->next = slow->next;

    return head;
}