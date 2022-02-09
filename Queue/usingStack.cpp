#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> st;

public:
    void enQueue(int x)
    {
        st.push(x);
    }
    int deQueue()
    {
        if (st.empty())
            return -1;

        int x = st.top();
        st.pop();

        if (st.empty())
            return x;

        int item = deQueue();

        st.push(x);

        return item;
    }
};
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}