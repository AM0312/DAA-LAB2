#include <bits/stdc++.h>
using namespace std;

int knapsackRec(vector<int> prices, vector<int> weights, int N, int W)
{
    if (N == 0 or W == 0)
        return 0;
    int inc = 0, exc = 0;
    if (weights[N - 1] <= W)
        inc = prices[N - 1] + knapsackRec(prices, weights, N - 1, W - weights[N - 1]);
    exc = knapsackRec(prices, weights, N - 1, W);
    return max(inc, exc);
}

int knapsackDpBottomUp(vector<int> prices, vector<int> weights, int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= W; w++)
        {
            int inc = 0, exc = 0;
            if (weights[n - 1] <= w)
                inc = prices[n - 1] + dp[n - 1][w - weights[n - 1]];
            exc = dp[n - 1][w];
            dp[n][w] = max(inc, exc);
        }
    }
    return dp[N][W];
}

auto main() -> int
{
    vector<int> prices{1, 5, 8, 10};
    vector<int> weights{4, 8, 13, 15};
    int W = 25;
    cout << knapsackRec(prices, weights, 4, W) << endl
         << knapsackDpBottomUp(prices, weights, 4, W) << endl;
}