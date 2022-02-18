
#include <bits/stdc++.h>
void change(char *x[])
{
    *x[0] = '1';
}
int main()
{
    char *s[5];
    *s = 'a';
    change(s);
    std::cout << *s[0] << std::endl;
}