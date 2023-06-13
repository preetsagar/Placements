// Link - https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; 

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode *t = new QueueNode(x);
    if(front==NULL){
        front = t;
        rear = t;
        return;
    }
    rear->next = t;
    rear = rear->next;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL) return -1;
    if(front==rear){    // only one element
        int t = front->data;
        front = NULL;
        rear = NULL;
        return t;
    }
    int t= front->data;
    front = front->next;
    return t;
}