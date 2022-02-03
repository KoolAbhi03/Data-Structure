#include <iostream>
#define SIZE 10

using namespace std;
class Queue
{
private:
    int data[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
            return true;
        return false;
    }
    void enqueue(int num)
    {
        if (!isFull())
        {
            if (front == -1)
                front = 0;
            rear += 1;
            data[rear] = num;
            cout << "Inserted " << num << endl;
        }
        else
        {
            cout << "Queue is full!"
                 << endl;
        }
    }
    void dequeue()
    {
        if (!isEmpty())
        {
            int num;
            num = data[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            cout << "Deleted " << num << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            cout << "Queue -> ";
            for (int i = front; i <= rear; i++)
            {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);

    q.display();
    q.dequeue();
    q.display();
    return 0;
}
