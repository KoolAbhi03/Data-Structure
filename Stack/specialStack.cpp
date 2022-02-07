/* NOTE
 Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, . etc.
*/

#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    int min = -1;
    static const int demo = 9999;
    stack<int> st;

public:
    void push(int x)
    {
        if (st.empty() || x < min)
            min = x;
        st.push(x * demo + min);
        cout << "pushed: " << x << endl;
    }
    int pop()
    {
        if (st.empty())
        {
            cout << "empty stack" << endl;
            return INT_MIN;
        }
        int x = st.top() / demo;
        st.pop();
        if (!st.empty())
            min = st.top() & demo;
        else
            min = -1;
        cout << "popped: " << x << endl;
        return x;
    }
    int peek()
    {
        if (st.empty())
        {
            cout << "empty stack" << endl;
            return INT_MIN;
        }
        int x = st.top() / demo;
        return x;
    }
    int getMin() { return min; }
};
int main()
{
    SpecialStack s;

    vector<int> arr = {3, 2, 6, 1, 8, 5, 5, 5, 5};

    for (int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
        s.getMin();
    }

    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        s.pop();
        s.getMin();
    }
    return 0;
}