#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int stack[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}
bool Stack::push(int x)
{
    if (top == MAX - 1)
        return false;

    stack[++top] = x;
    cout << x << " pushed in stack!" << endl;
    return true;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        int x = stack[top--];
        return x;
    }
}
int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        int x = stack[top];
        return x;
    }
}
int main()
{
    Stack s;
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    // print all elements in stack :
    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}