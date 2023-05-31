// Link - https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode *reverse(ListNode *head, int &k, int &remaining)
    {
        if (!head || !head->next)
        {
            return head;
        }
        if (remaining >= k) // note
        {
            ListNode *temp = head, *newHead = NULL;
            int c = 0;
            while (c < k && temp)
            {
                ListNode *next = temp->next;
                temp->next = newHead;
                newHead = temp;
                temp = next;
                c++;
                remaining--;
            }
            head->next = reverse(temp, k, remaining);
            return newHead;
        }
        return head;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        // cout<<len<<endl;

        return reverse(head, k, len);
    }
};