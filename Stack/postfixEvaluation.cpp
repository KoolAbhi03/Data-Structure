#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;

        else if (isdigit(s[i]))
        {
            int num = 0;
            while (s[i] != ' ')
            {
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            st.push(num);
            i--;
        }
        else
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if (s[i] == '/')
                st.push((int)(y / x));
            else if (s[i] == '*')
                st.push(x * y);
            else if (s[i] == '+')
                st.push(x + y);
            else
                st.push(y - x);
        }
    }
    int x = st.top();
    st.pop();
    return x;
}
int main()
{
    string exp = "2 3 1 * + 9 -";
    cout << postfixEvaluation(exp);
    return 0;
}