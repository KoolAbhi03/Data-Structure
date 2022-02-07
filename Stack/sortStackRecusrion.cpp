#include <bits/stdc++.h>
using namespace std;

stack<int> st;
void insertAtRightPlace(int x)
{
    if (st.empty() || (x > st.top()))
        st.push(x);
    else
    {
        int y = st.top();
        st.pop();
        insertAtRightPlace(x);
        st.push(y);
    }
}
void sort()
{
    if (!st.empty())
    {
        int x = st.top();
        st.pop();
        sort();
        insertAtRightPlace(x);
    }
}
int main()
{
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    sort();
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}