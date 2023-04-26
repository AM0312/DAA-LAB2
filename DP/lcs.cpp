#include <bits/stdc++.h>
using namespace std;

int lcsRec(string s1, string s2, int i, int j)
{
    if (i == s1.length() or j == s2.length())
        return 0;
    if (s1[i] == s2[j])
        return 1 + lcsRec(s1, s2, i + 1, j + 1);
    int op1 = lcsRec(s1, s2, i + 1, j);
    int op2 = lcsRec(s1, s2, i, j + 1);
    return max(op1, op2);
}

int lcsDpTopDown(string s1, string s2, int i, int j, vector<vector<int>> dp)
{
    if (i == s1.length() or j == s2.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsDpTopDown(s1, s2, i + 1, j + 1, dp);
    int op1 = lcsDpTopDown(s1, s2, i + 1, j, dp);
    int op2 = lcsDpTopDown(s1, s2, 1, j + 1, dp);
    return dp[i][j] = max(op1, op2);
}

int lcsDpBottomUp(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}

auto main() -> int
{
    string s1 = "abcd", s2 = "bcd";
    vector<vector<int>> dp(s1.length() + 1, (vector<int>(s2.length() + 1, -1)));
    cout << lcsRec(s1, s2, 0, 0) << endl
         << lcsDpTopDown(s1, s2, 0, 0, dp) << endl
         << lcsDpBottomUp(s1, s2) << endl;
}