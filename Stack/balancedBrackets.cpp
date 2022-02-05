#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

        else
        {
            if (st.empty())
                return false;
            if (s[i] = ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (s[i] = '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (s[i] = ']' && st.top() == '[')
            {
                st.pop();
            }
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}
int main()
{
    string expr = "[{}";

    // Function call
    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}