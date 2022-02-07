#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void insertAtBottom(int x)
{
    if (st.size() == 0)
        st.push(x);
    else
    {
        int y = st.top();
        st.pop();
        insertAtBottom(x);
        st.push(y);
    }
}
void reverseStack()
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        reverseStack();
        insertAtBottom(x);
    }
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseStack();

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}