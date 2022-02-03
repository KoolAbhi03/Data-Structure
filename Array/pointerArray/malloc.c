#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *z = NULL;
    z = (char *)malloc(10);

    if (!z)
    {
        perror("failed to allocate memory");
        exit(1);
    }
    strcpy(z, "WElcome");
    printf("%s", z);
}