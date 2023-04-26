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
            for (it = l[i].begin(); it != l[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    bool isSafe(int v, vector<bool> visited)
    {
        if (visited[v])
            return false;

        visited[v] = true;
        path.push_back(v);

        if (path.size() == V)
        {
            return true;
        }

        bool res = false;

        list<int>::iterator it;
        for (it = l[v].begin(); it != l[v].end(); it++)
        {
            if (isSafe(*it, visited))
            {
                res = true;
                break;
            }
        }

        if (!res)
        {
            visited[v] = false;
            path.pop_back();
        }

        return res;
    }

    bool hamiltonianPath()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            path.clear();
            visited[i] = true;
            path.push_back(i);
            if (isSafe(i, visited))
            {
                for (int vertex : path)
                {
                    cout << vertex << " ";
                }
                cout << endl;
                return true;
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
