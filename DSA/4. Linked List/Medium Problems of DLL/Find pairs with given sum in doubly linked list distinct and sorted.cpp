// Link - https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        Node *start = head, *end, *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }
        end = temp;

        while (start != end)
        {
            if (start->data + end->data == target)
            {
                ans.push_back({start->data, end->data});
                start = start->next;
            }
            else if (start->data + end->data < target)
            {
                start = start->next;
            }
            else
            {
                end = end->prev;
            }
        }

        return ans;
    }
};