// Link - https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

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

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        Node *temp = head->next;
        while (temp)
        {
            if (temp->data == temp->prev->data)
            {
                temp->prev->next = temp->next;
                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};