#include <stdio.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
void print(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    bubblesort(arr, n);
    print(arr, n);
    return 0;
}
