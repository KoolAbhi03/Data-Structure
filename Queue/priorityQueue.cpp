#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    }
};

class PQueue
{
    Node *head = NULL;

public:
    void enQueue(int data, int prior)
    {
        Node *new_node = new Node(data, prior);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        if (head->priority > prior)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority < prior)
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    void deQueue()
    {
        if (head == NULL)
        {
            cout << "Queue Empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int peek()
    {
        return head->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};
int main()
{

    // Create a Priority Queue
    // 7->4->5->6
    PQueue pq;
    pq.enQueue(4, 1);
    pq.enQueue(5, 2);
    pq.enQueue(6, 3);
    pq.enQueue(7, 0);
    while (!pq.isEmpty())
    {
        cout << " " << pq.peek();
        pq.deQueue();
    }
    return 0;
}