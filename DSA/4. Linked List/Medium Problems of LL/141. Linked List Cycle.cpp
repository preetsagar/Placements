// Link - https://leetcode.com/problems/linked-list-cycle/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        // Method 1
        // unordered_map<ListNode *, int> m;
        // while(head && m.find(head)==m.end()){
        //     m[head]++;
        //     head = head->next;
        // }
        // return head==NULL ? 0 : 1;

        // Method 2
        // if(head==NULL){
        //     return 0;
        // }
        // ListNode *fast=head->next, *slow=head;
        // while(fast && fast!=slow){
        //     fast = fast->next;
        //     slow = slow->next;
        //     if(fast){
        //         fast = fast->next;
        //     }
        // }
        // if(fast==NULL){
        //     return 0;
        // }
        // return 1;

        // Method 3
        ListNode *dummy = new ListNode(INT_MAX);
        while (head && head != dummy)
        {
            ListNode *next = head->next;
            head->next = dummy;

            head = next;
        }
        return head == NULL ? 0 : 1;
    }
};