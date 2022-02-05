#include <bits/stdc++.h>
using namespace std;

void reverse(char *s)
{
    stack<char> st;
    for (int i = 0; s[i]; i++)
        st.push(s[i]);

    for (int i = 0; s[i]; i++)
    {
        s[i] = st.top();
        st.pop();
    }
}
int main()
{
    char str[] = "Vincenzo";

    reverse(str);
    cout << "Reversed string is " << str;

    return 0;
}