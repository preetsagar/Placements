// Link - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if (!head || !head->next)
        {
            return head;
        }
        node *temp = head, *newHead = NULL;
        int c = 0;
        while (c < k && temp)
        {
            node *next = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = next;
            c++;
        }
        head->next = reverse(temp, k);
        return newHead;
    }
};