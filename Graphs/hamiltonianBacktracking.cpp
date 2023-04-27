#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    vector<int> path;

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
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    bool isSafe(int v, vector<bool> &visited)
    {
        if (visited[v])
            return false;

        if (path.size() == V)
            return true;

        visited[v] = true;

        list<int>::iterator it;
        for (it = l[v].begin(); it != l[v].end(); it++)
        {
            if (isSafe(*it, visited))
            {
                path.push_back(*it);
                return true;
            }
        }
        visited[v] = false;
        return false;
    }

    bool hamiltonianPath()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            path.clear();
            path.push_back(i);
            visited[i] = true;

            list<int>::iterator it;
            for (it = l[i].begin(); it != l[i].end(); it++)
            {
                if (isSafe(*it, visited))
                {
                    path.push_back(*it);
                    return true;
                }
            }
            visited[i] = false;
        }
        return false;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 0);
    g.printgraph();
    cout << g.hamiltonianPath() << endl;
    return 0;
}
