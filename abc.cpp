#include <stdio.h>
void change(int *x)
{
    *x = 5;
}
int main()
{
    int *x;
    int y = 2;
    x = &y;
    printf("%d", *x);
    change(x);
    printf("%d", 2 * *2);
}