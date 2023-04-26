#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int i, int j, vector<int> dim)
{
    if (i == j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = matrixChainMultiplication(i, k, dim) + matrixChainMultiplication(k + 1, j, dim) + dim[i - 1] * dim[k] * dim[j];
        ans = min(ans, cost);
    }
    return ans;
}

int matrixChainMultiplicationDpTopDown(int i, int j, vector<vector<int>> dp, vector<int> dim, vector<vector<int>> k)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int temp = i; temp < j; temp++)
    {
        int cost = matrixChainMultiplicationDpTopDown(i, temp, dp, dim, k) + matrixChainMultiplicationDpTopDown(temp + 1, j, dp, dim, k) + dim[i - 1] * dim[temp] * dim[j];
        if (cost < ans)
        {
            ans = cost;
            k[i][j] = temp;
        }
    }
    return dp[i][j] = ans;
}

auto main() -> int
{
    vector<int> dim{10, 20, 10, 30, 50};
    vector<vector<int>> dp(1000, vector<int>(1000, -1));
    vector<vector<int>> k(1000, vector<int>(1000, 0));
    cout << matrixChainMultiplication(1, 4, dim) << endl
         << matrixChainMultiplicationDpTopDown(1, 4, dp, dim, k) << endl;
}