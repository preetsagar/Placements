// Link - https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0

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

class Solution
{
public:
    // Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        return temp;
    }

    // Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)
    {
        if (head == NULL)
        {
            head = new Node(x);
            return head;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(x);
        return head;
    }
};