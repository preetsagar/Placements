// Link - https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = 1, len2 = 1;
        ListNode *t1 = headA, *t2 = headB;
        while (t1)
        {
            len1++;
            t1 = t1->next;
        }
        while (t2)
        {
            len2++;
            t2 = t2->next;
        }
        while (len1 > len2)
        {
            headA = headA->next;
            len1--;
        }
        while (len1 < len2)
        {
            headB = headB->next;
            len2--;
        }

        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};