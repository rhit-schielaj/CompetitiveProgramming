#include <bits/stdc++.h>

/**
 * This solution basically just brute forces every expected button push with every actual button push,
 * then just consistently chooses the button match points max as it iterrates through and adding as it
 * goes. At the end it has the best added points of all the buttons.
 */


std::vector<int> levels = {15, 23, 43, 102};
std::vector<int> points = {7, 6, 4, 2};

int getPoints(int e, int a)
{
    int d = abs(e - a);
    for (int i = 0; i < 4; i++)
        if (d <= levels[i])
            return points[i];
    return 0;
}

int main()
{
    int n, m;
    std::cin >> n >> m;                                               // expected button presses, actual button presses
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1)); // array of n+1 arrays of m+1 presses
    std::vector<int> expected(n);
    std::vector<int> actual(m); // lists of expected and actual button presses
    for (int i = 0; i < n; i++) // take in expected button presses
    {
        std::cin >> expected[i];
    }
    for (int i = 0; i < m; i++) // take in actual button presses
    {
        std::cin >> actual[i];
    }
    for (int i = 0; i <= n; i++) // loop over expected button presses + 1 at the end for leftovers
    {
        for (int j = 0; j <= m; j++) // loop over actual button presses + 1 at the end for leftovers
        {
            if (i < n)
            {
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);//set next value to be max of this or itself
            }
            if (j < m)
            {
                dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j]);//set next value to be max of this or itself
            }
            if (i < n && j < m)
            {
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + getPoints(expected[i], actual[j]));//set this value to be how well a certain button push matched another one
            }
        }
    }

    std::cout << dp[n][m] << "\n";
    return 0;
}
