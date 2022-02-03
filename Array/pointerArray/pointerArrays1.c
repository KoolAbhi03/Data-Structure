#include <stdio.h>
#include <stdlib.h>
void print(int *x[])
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d %16lu %16lu\n", **x, *x, x);
        x = x + 1;
    }
}
int main()
{
    int *x[6];
    int i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 5, i6 = 6;
    x[0] = &i1;
    x[1] = &i2;
    x[2] = &i3;
    x[3] = &i4;
    x[4] = &i5;
    x[5] = &i6;

    for (int i = 0; i < 6; i++)
    {
        printf("%16u %16u %d\n", x[i], x[i], x[i]);
    }
    print(x);
    return 0;
}