// Link - https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *h1 = l1, *h2 = l2;
        int n, r = 0;
        while (l1 && l2)
        {
            n = l1->val + l2->val + r;
            l1->val = n % 10;
            l2->val = n % 10;
            r = n / 10;
            if (!l1->next && !l2->next && r > 0)
            {
                l1->next = new ListNode(r);
                r = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
        {
            while (l1)
            {
                n = l1->val + r;
                l1->val = n % 10;
                r = n / 10;
                if (!l1->next && r > 0)
                {
                    l1->next = new ListNode(r);
                    r = 0;
                }

                l1 = l1->next;
            }
            return h1;
        }
        if (l2)
        {
            while (l2)
            {
                n = l2->val + r;
                l2->val = n % 10;
                r = n / 10;
                if (!l2->next && r > 0)
                {
                    l2->next = new ListNode(r);
                    r = 0;
                }

                l2 = l2->next;
            }
            return h2;
        }

        return h2;
    }
};