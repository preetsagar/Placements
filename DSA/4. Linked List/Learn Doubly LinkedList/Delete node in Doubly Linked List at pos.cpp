// Link - https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        if (x == 1)
        {
            head = head->next;
            if (head->next)
            {
                head->next->prev = head;
            }
            return head;
        }
        Node *fast = head, *slow = head;

        while (fast != NULL and --x)
        {
            slow = fast;
            fast = fast->next;
        }
        if (!x)
        {
            slow->next = fast->next;
            if (fast->next)
            {
                fast->next->prev = slow;
            }
        }
        return head;
    }
};