// Link - https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

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

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        // Write your code here
        Node *head = (*head_ref), *temp = (*head_ref), *slow = (*head_ref);

        while (head)
        {
            if (head->data == x)
            {
                if (head->prev == NULL)
                {
                    head = head->next;
                    temp = temp->next;
                    if (head)
                    {
                        head->prev = NULL;
                    }
                }
                else
                {
                    head = head->next;
                    slow->next = head;
                    if (head)
                    {
                        head->prev = slow;
                    }
                }
            }
            else
            {
                slow = head;
                head = head->next;
            }
        }
        (*head_ref) = temp;
    }
};