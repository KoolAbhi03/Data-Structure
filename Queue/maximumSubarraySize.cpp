/*NOTE
Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
Output: 3 3 4 5 5 5 6
Explanation:
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6*/

#include <bits/stdc++.h>
using namespace std;

void maximumOfSubArray(int arr[], int n, int k)
{
    deque<int> q(k);
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[q.front()] << " ";

        while (!q.empty() && q.front() <= i - k)
            q.pop_front();

        while (!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }
    cout << arr[q.front()];
}
int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    maximumOfSubArray(arr, n, k);
    return 0;
}