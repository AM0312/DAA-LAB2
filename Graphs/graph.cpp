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

    void addEdge(int u, int v, bool directed = false)
    {
        l[u].push_back(v);
        if (!directed)
            l[v].push_back(u);
    }

    void printgraph()
    {
        for (int i = 0; i < V; i++)
        {
            list<int>::iterator it;
            cout << i << ": ";
            for (it = l[i].begin(); it != l[i].end(); it++)
            {
                cout << *it << "-->";
            }
            cout << endl;
        }
    }
};

auto main() -> int
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.printgraph();
}