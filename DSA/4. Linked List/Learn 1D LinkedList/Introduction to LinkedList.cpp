// Link - https://practice.geeksforgeeks.org/problems/introduction-to-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        Node *head = NULL, *temp = NULL;
        for (int i : arr)
        {
            if (!head)
            {
                head = new Node(i);
                temp = head;
            }
            else
            {
                temp->next = new Node(i);
                temp = temp->next;
            }
        }
        return head;
    }
};