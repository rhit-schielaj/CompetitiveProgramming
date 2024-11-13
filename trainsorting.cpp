#include <bits/stdc++.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    std::vector<int> order(n, 0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &order[i]);
    }
    int max = 0;
    if (n > 0)
    {
        max = 1;
    }

    std::vector<int> dpi(n, 1);
    std::vector<int> dpd(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (order[j] < order[i])
            {
                dpd[i] = std::max(dpd[i], dpd[j] + 1);
            }
            if (order[j] > order[i])
            {
                dpi[i] = std::max(dpi[i], dpi[j] + 1);
            }
        }
        max = std::max(max, dpd[i] + dpi[i] - 1);
    }

    printf("%d", max);
}
