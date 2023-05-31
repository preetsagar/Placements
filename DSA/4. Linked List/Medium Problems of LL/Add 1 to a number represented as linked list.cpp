// Link - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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
    Node *reverse(Node *head)
    {
        Node *newHead = NULL;
        while (head)
        {
            Node *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }

    Node *addOne(Node *head)
    {
        head = reverse(head);
        Node *t = head;
        int n, r = 1;
        while (t)
        {
            n = t->data + r;
            if (t->next)
            {
                t->data = n % 10;
            }
            else
            {
                t->data = n;
            }
            r = n / 10;

            t = t->next;
        }
        head = reverse(head);
        return head;
    }
};