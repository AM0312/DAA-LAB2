#include <bits/stdc++.h>
using namespace std;

int coinChangeMinCoinsDP(int amt, vector<int> denoms)
{
    vector<vector<int>> dp(denoms.size() + 1, vector<int>(amt + 1, 0));

    for (int j = 0; j <= amt; j++)
        dp[0][j] = j;

    for (int i = 1; i <= denoms.size(); i++)
    {
        for (int j = 1; j <= amt; j++)
        {
            if (denoms[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - denoms[i - 1]] + 1);
        }
    }
    return dp[denoms.size()][amt];
}

int coinChangeWaysDP(int amt, vector<int> denoms)
{
    vector<vector<int>> dp(denoms.size() + 1, vector<int>(amt + 1, 0));
    for (int i = 0; i <= denoms.size(); i++)
        dp[i][0] = 1;
    for (int i = 1; i <= denoms.size(); i++)
    {
        for (int j = 1; j <= amt; j++)
        {
            if (denoms[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - denoms[i - 1]];
        }
    }
    return dp[denoms.size()][amt];
}

auto main() -> int
{
    vector<int> denoms{2, 5, 6, 9};
    int amt = 10;
    cout << coinChangeMinCoinsDP(amt, denoms) << endl
         << coinChangeWaysDP(amt, denoms) << endl;
}
