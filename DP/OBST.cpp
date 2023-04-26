#include <bits/stdc++.h>
using namespace std;

int calcWeight(int i, int j, vector<int> freq)
{
    int w = 0;
    for (int k = i; k <= j; k++)
        w += freq[k];
    return w;
}

int optimalBST(int i, int j, vector<int> keys, vector<int> freq)
{
    if (i > j)
        return 0;
    if (i == j)
        return freq[i];
    int ans = INT_MAX;
    int weight = calcWeight(i, j, freq);
    for (int k = i; k <= j; k++)
    {
        int temp = optimalBST(i, k - 1, keys, freq) + optimalBST(k + 1, j, keys, freq);
        ans = min(ans, temp);
    }
    return ans + weight;
}

int optimalBSTDPTopDown(int i, int j, vector<int> keys, vector<int> freq, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return freq[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    int weight = calcWeight(i, j, freq);
    for (int k = i; k <= j; k++)
    {
        int temp = optimalBSTDPTopDown(i, k - 1, keys, freq, dp) + optimalBSTDPTopDown(k + 1, j, keys, freq, dp);
        ans = min(ans, temp);
    }
    return dp[i][j] = ans + weight;
}

auto main() -> int
{
    vector<int> keys{10, 20, 30, 40};
    vector<int> freq{4, 2, 6, 3};
    vector<vector<int>> dp(1000, (vector<int>(1000, -1)));
    cout << optimalBST(0, 3, keys, freq) << endl
         << optimalBSTDPTopDown(0, 3, keys, freq, dp) << endl;
}