// Link - https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

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
        next = prev = NULL;
    }
};

// Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
    Node *slow = head, *fast = head->next;
    while (--pos >= 0 && fast != NULL)
    {
        slow = fast;
        fast = fast->next;
    }
    if (fast != NULL)
    {
        // cout<<slow->data<<endl;
        Node *temp = new Node(data);
        temp->next = slow->next;
        temp->prev = slow;

        slow->next = temp;
    }
    else
    {
        // cout<<"Holla"<<endl;
        // cout<<slow->data<<endl;
        Node *temp = new Node(data);
        temp->next = NULL;
        temp->prev = slow;

        slow->next = temp;
    }
}