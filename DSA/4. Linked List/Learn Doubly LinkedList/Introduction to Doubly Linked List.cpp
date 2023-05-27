// Link - https://practice.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        Node *head = NULL, *temp = NULL;

        for (int i : arr)
        {
            if (head == NULL)
            {
                head = new Node(i);
                temp = head;
            }
            else
            {
                Node *t = new Node(i);
                temp->next = t;
                t->prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};