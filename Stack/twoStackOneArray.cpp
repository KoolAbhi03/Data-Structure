#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr, size, top1, top2;

public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int x)
    {
        if (top1 < top2 - 1)
            arr[++top1] = x;
        else
            cout << "Stack Overflow\n";
    }
    void push2(int x)
    {
        if (top1 < top2 - 1)
            arr[--top2] = x;
        else
            cout << "Stack Overflow\n";
    }
    int pop1()
    {
        if (top1 == -1)
            cout << "Stack Underflow\n";
        else
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        return INT_MIN;
    }
    int pop2()
    {
        if (top2 == size)
            cout << "Stack Underflow\n";
        else
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        return INT_MIN;
    }
};
int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2();
    return 0;
}