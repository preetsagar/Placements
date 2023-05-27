// Link - https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Link list Node
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

/*You are required to complete below method*/
Node *deleteNode(Node *head, int x)
{
    if (x == 1)
    {
        return head->next;
    }

    Node *slow = head, *fast = head;
    while (--x && fast->next != NULL)
    {
        slow = fast;
        fast = fast->next;
    }
    if (x == 0)
    {
        slow->next = fast->next;
    }

    return head;
}