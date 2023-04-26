#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    vector<bool> visited;
    vector<int> topologicalOrder;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
        visited.resize(V, false);
    }

    void addEdge(int u, int v, bool direction = false)
    {
        l[u].push_back(v);
        if (!direction)
            l[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << ": ";
            for (int j : l[i])
                cout << j << " ";
            cout << endl;
        }
    }

    void dfs(int v)
    {
        visited[v] = true;

        for (int u : l[v])
        {
            if (!visited[u])
                dfs(u);
        }

        topologicalOrder.push_back(v);
    }

    vector<int> topologicalSort()
    {
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        reverse(topologicalOrder.begin(), topologicalOrder.end());
        return topologicalOrder;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(0, 3, true);
    g.addEdge(2, 4, true);
    g.addEdge(3, 4, true);

    g.printGraph();

    vector<int> topologicalOrder = g.topologicalSort();

    cout << "Topological Order: ";
    if (topologicalOrder.empty())
        cout << "None" << endl;
    else
    {
        for (int v : topologicalOrder)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
