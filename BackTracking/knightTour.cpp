#include <bits/stdc++.h>
using namespace std;

int isSafe(int x, int y, const vector<vector<int>> &sol, int N)
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int solveKTUtil(int x, int y, int movei, vector<vector<int>> &sol, vector<int> &xMove, vector<int> &yMove)
{
    int k, next_x, next_y;
    int N = sol.size();
    if (movei == N * N)
        return 1;

    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol, N))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

void printSolution(const vector<vector<int>> &sol, int N)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

int solveKT(int N)
{
    vector<vector<int>> sol(N, vector<int>(N, -1));

    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;

    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol, N);

    return 1;
}

int main()
{
    int N;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> N;

    solveKT(N);
    return 0;
}
