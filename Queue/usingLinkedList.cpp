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
        this->next = NULL;
    }
};
class Queue
{
public:
    QNode *front, *rear;
    Queue() { front = rear = NULL; }
    void enQueue(int x)
    {
        QNode *new_node = new QNode(x);
        if (rear == NULL)
        {
            front = rear = new_node;
            return;
        }

        rear->next = new_node;
        rear = new_node;
    }
    void deQueue()
    {
        if (front == NULL)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        QNode *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
};
int main()
{

    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}