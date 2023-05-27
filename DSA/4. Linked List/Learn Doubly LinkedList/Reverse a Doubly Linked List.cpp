// Link - https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t = temp->next;
        temp->next = temp->prev;
        temp->prev = t;

        if (!t)
        {
            head = temp;
        }
        temp = t;
    }
    return head;
}