#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<bool>> &graph, vector<int> &color, int c, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<bool>> &graph, int m, vector<int> &color, int v, int size)
{
    if (v == size)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c, size))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, size))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void printSolution(vector<int> &color, int size)
{
    cout << "Solution Exists: Following are the assigned colors\n";
    for (int i = 0; i < size; i++)
        cout << color[i] << " ";
    cout << "\n";
}

bool graphColoring(vector<vector<bool>> &graph, int m, int size)
{
    vector<int> color(size, 0);

    if (graphColoringUtil(graph, m, color, 0, size) == false)
    {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(color, size);
    return true;
}

int main()
{
    int size = 4;
    vector<vector<bool>> graph = {
        {false, true, true, true},
        {true, false, true, false},
        {true, true, false, true},
        {true, false, true, false}};
    int m = 3;
    graphColoring(graph, m, size);
    return 0;
}
