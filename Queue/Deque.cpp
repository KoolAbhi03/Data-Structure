/* NOTE
insertFront(): Adds an item at the front of Deque.
insertLast(): Adds an item at the rear of Deque.
deleteFront(): Deletes an item from front of Deque.
deleteLast(): Deletes an item from rear of Deque.

In addition to above operations, following operations are also supported
getFront(): Gets the front item from queue.
getRear(): Gets the last item from queue.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = NULL;
    Node *next = NULL;
    Node(int data)
    {
        this->data = data;
    }
};

class Deque
{
    Node *front, *rear;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
    }
    void insertFront(int data)
    {
        Node *temp = new Node(data);
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
            return;
        }
        front->prev = temp;
        temp->next = front;
        front = temp;
    }
    void insertLast(int data)
    {
        Node *temp = new Node(data);
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
    void deleteFront()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "empty deque" << endl;
            return;
        }
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
            return;
        }
        Node *temp = front;
        front = front->next;
        front->prev = NULL;
        delete temp;
    }
    void deleteLast()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "empty deque" << endl;
            return;
        }
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
            return;
        }
        Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        delete temp;
    }
    int getFront()
    {
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }
};

int main()
{
    Deque dq;
    dq.insertFront(1);
    dq.insertLast(2);
    cout << dq.getRear() << endl;
    dq.deleteLast();
    cout << dq.getRear() << endl;
    dq.deleteLast();
    dq.deleteLast();
    dq.deleteLast();
}