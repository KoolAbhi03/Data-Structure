#include <bits/stdc++.h>
using namespace std;

class QNode
{
public:
    int data;
    QNode *next;
    QNode(int data)
    {
        this->data = data;
    }
};
class Queue
{
public:
    QNode *front, *rear;
    Queue() { front = rear = NULL; }
    void enQueue()
    {
    }
};