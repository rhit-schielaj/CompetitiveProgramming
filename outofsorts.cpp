#include <bits/stdc++.h>

std::vector<int> arr;

int main()
{
    int n, m, a, c, x;

    scanf("%d %d %d %d %d", &n, &m, &a, &c, &x);
    arr.resize(n, 0);
    a = a % m;
    c = c % m;
    arr[0] = x;
    arr[0] = (int)(((long)((long)x * (long)a) + (long)c) % m);
    for (int i = 1; i < n; i++)
    {
        long temp = ((long)((long)arr[i - 1] * (long)a) + (long)c) % m;
        arr[i] = (int)temp;
    }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     fprintf(stderr, "%d ", arr[i]);
    // }
    fprintf(stderr, "\n");

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // fprintf(stderr, "got here");
        //Binary Search:
        bool found = false;
        int target = arr[i];
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2; // Calculate mid-point

            // Check if target is at mid
            if (arr[mid] == target)
            {
                found = true;
                break;
            }
            // If target is greater, ignore left half
            else if (arr[mid] > target)
            {
                right = mid - 1;
            }
            // If target is smaller, ignore right half
            else
            {
                left = mid + 1;
            }
        }
        if (found)
        {
            // fprintf(stderr, "found: %d\n", arr[i]);
            count++;
        }
    }
    printf("%d", count);
    // fprintf(stderr, "&d\n", checkBS((n/2)+1, std::round(n/4)));
}
