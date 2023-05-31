// Link - https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

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

// Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    if (!head || !head->next)
    {
        return 0;
    }

    Node *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int len = 1;
            slow = slow->next;
            while (slow != fast)
            {
                len++;
                slow = slow->next;
            }
            return len;
        }
    }
    return 0;
}