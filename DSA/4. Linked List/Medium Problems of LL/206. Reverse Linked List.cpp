// Link - https://leetcode.com/problems/reverse-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *curr, ListNode *prev)
    {
        if (curr->next == NULL)
        {
            curr->next = prev;
            return curr;
        }

        ListNode *temp = curr->next;
        curr->next = prev;
        return reverse(temp, curr);
    }

    ListNode *reverse2(ListNode *curr)
    {
        if (curr == NULL || curr->next == NULL)
        {
            return curr;
        }

        ListNode *newNode = reverse2(curr->next);
        curr->next->next = curr;
        curr->next = NULL;

        return newNode;
    }

    ListNode *reverseList(ListNode *head)
    {

        // iterative method 1
        // ListNode *newNode = NULL;
        // while(head){
        //     ListNode *next = head->next;
        //     head->next = newNode;

        //     newNode = head;
        //     head = next;
        // }
        // return newNode;

        return reverse2(head);

        // Iterative method 2
        // ListNode *p=NULL, *q=NULL, *r=head;
        // while(r){
        //     if(q){
        //         q->next = p;
        //     }
        //     p = q;
        //     q = r;
        //     r = r->next;
        // }
        // if(q){
        //     q->next = p;
        // }
        // return q;

        // if(head==NULL){
        //     return head;
        // }
        // return reverse(head, NULL);
    }
};