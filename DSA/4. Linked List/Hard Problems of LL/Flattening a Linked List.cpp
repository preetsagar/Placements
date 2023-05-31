// Link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    if (!root || !root->next)
    {
        return root;
    }
    Node *right = flatten(root->next);

    // Merge to LL
    Node *dummy = new Node(-1), *temp;
    temp = dummy;
    while (right && root)
    {
        if (right->data < root->data)
        {
            Node *bottom = right->bottom;
            temp->bottom = right;
            temp = temp->bottom;
            temp->bottom = NULL;
            right = bottom;
        }
        else
        {
            Node *bottom = root->bottom;
            temp->bottom = root;
            temp = temp->bottom;
            temp->bottom = NULL;
            root = bottom;
        }
    }
    if (right)
    {
        temp->bottom = right;
    }
    if (root)
    {
        temp->bottom = root;
    }

    return dummy->bottom;
}
