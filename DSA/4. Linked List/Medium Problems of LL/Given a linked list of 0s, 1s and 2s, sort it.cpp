// Link - https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        Node *zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);
        Node *t0 = zero;
        Node *t1 = one;
        Node *t2 = two;

        while (head)
        {
            if (head->data == 0)
            {
                t0->next = head;
                head = head->next;
                t0 = t0->next;
                t0->next = NULL;
            }
            else if (head->data == 1)
            {
                t1->next = head;
                head = head->next;
                t1 = t1->next;
                t1->next = NULL;
            }
            else if (head->data == 2)
            {
                t2->next = head;
                head = head->next;
                t2 = t2->next;
                t2->next = NULL;
            }
        }

        t1->next = two->next;
        t0->next = one->next;

        return zero->next;
    }
};