#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
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

    vector<int> topologicalSort()
    {
        vector<int> inDegree(V, 0);

        for (int u = 0; u < V; u++)
        {
            for (int v : l[u])
                inDegree[v]++;
        }

        queue<int> q;
        for (int u = 0; u < V; u++)
        {
            if (inDegree[u] == 0)
                q.push(u);
        }

        vector<int> topologicalOrder;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topologicalOrder.push_back(u);

            for (int v : l[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        if (topologicalOrder.size() != V)
            return vector<int>();

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
    {
        cout << "None" << endl;
    }
    else
    {
        for (int v : topologicalOrder)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
