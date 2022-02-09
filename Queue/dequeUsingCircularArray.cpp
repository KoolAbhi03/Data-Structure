#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int size, *arr, front = -1, rear = -1;

public:
    Deque(int n)
    {
        this->size = n;
        this->arr = new int[n];
    }
    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void insertFront(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
            rear++;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }
    void insertRear(int data)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1)
        {
            front++;
            rear++;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Empty Queue\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            if (front == size - 1)
                front = 0;
            else
                front++;
        }
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << " Underflow\n";
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << " Underflow\n"
                 << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty() || rear < 0)
        {
            cout << " Underflow\n"
                 << endl;
            return -1;
        }
        return arr[rear];
    }
};
int main()
{
    Deque dq(5);
    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);

    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);

    cout << "get rear element "
         << " "
         << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;

    cout << "inserting element at front end \n";
    dq.insertFront(15);

    cout << "get front element "
         << " "
         << dq.getFront() << endl;

    dq.deleteFront();

    cout << "After delete front element new "
         << "front become " << dq.getFront() << endl;
    return 0;
}