// Link - https://practice.geeksforgeeks.org/problems/sort-a-stack/1

#include <bits/stdc++.h>
using namespace std;

// Method 1
void solve(stack<int> &s, int temp)
{
    if (s.empty())
    {
        s.push(temp);
        return;
    }
    int t1 = s.top();
    s.pop();
    if (t1 < temp)
    {
        solve(s, t1);
        s.push(temp);
        return;
    }
    solve(s, temp);
    s.push(t1);
    return;
}
void sort(stack<int> s)
{
    // Your code here
    int i = 0;
    while (i < s.size())
    {
        int t1 = s.top();
        s.pop();
        solve(s, t1);
        i++;
    }
}

// Method 2
void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || temp > s.top())
    {
        s.push(temp);
    }
    else
    {
        int top = s.top();
        s.pop();
        insert(s, temp);
        s.push(top);
    }
}
void sort(stack<int> s)
{
    if (s.size() > 0)
    {
        int top = s.top();
        s.pop();
        sort(s);
        insert(s, top);
    }
}