// Link - https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Method 1
        // map<Node*, Node *> m;
        // Node *temp=head;
        // while(temp){
        //     Node *newNode = new Node(temp->val);
        //     m[temp] = newNode;
        //     temp = temp->next;
        // }
        // temp=head;
        // while(temp){
        //     Node *t = m[temp];
        //     if(temp->next){
        //         t->next = m[temp->next];
        //     }
        //     if(temp->random){
        //         t->random = m[temp->random];
        //     }
        //     temp = temp->next;
        // }
        // return m[head];

        // Method 2;
        // Step 1 add new node with same val just next to it
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Step 2 arrange the random pointer for the newly created node
        temp = head;
        while (temp)
        {
            if (temp->random)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Rearrange the original and deep copy
        Node *cloneHead = new Node(-1);
        temp = head;
        Node *dummy = cloneHead;

        while (temp)
        {
            dummy->next = temp->next;
            dummy = dummy->next;

            temp->next = dummy->next;
            dummy->next = NULL;
            temp = temp->next;
        }

        return cloneHead->next;
    }
};