#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    vector<int> eulerCircuit;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
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

    void dfs(int v, vector<bool> &visited)
    {
        visited[v] = true;

        for (int u : l[v])
        {
            if (!visited[u])

                dfs(u, visited);
        }
    }

    bool isConnected()
    {
        vector<bool> visited(V, false);

        int startVertex = -1;
        for (int i = 0; i < V; i++)
        {
            if (!l[i].empty())
            {
                startVertex = i;
                break;
            }
        }

        if (startVertex == -1)

            return true;

        dfs(startVertex, visited);

        for (int i = 0; i < V; i++)
        {
            if (!l[i].empty() && !visited[i])

                return false;
        }

        return true;
    }

    int countOddDegreeVertices()
    {
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (l[i].size() % 2 != 0)

                count++;
        }
        return count;
    }

    vector<int> findEulerianPath()
    {
        vector<int> path;
        if (!isConnected() || countOddDegreeVertices() > 2)
            return path;

        int startVertex = 0;
        for (int i = 0; i < V; i++)
        {
            if (l[i].size() % 2 != 0)
            {
                startVertex = i;
                break;
            }
        }

        stack<int> st;
        st.push(startVertex);

        while (!st.empty())
        {
            int u = st.top();
            if (!l[u].empty())
            {
                int v = l[u].front();
                st.push(v);
                l[u].remove(v);
                l[v].remove(u);
            }
            else
            {
                path.push_back(u);
                st.pop();
            }
        }

        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(0, 6);
    g.addEdge(0, 7);
    g.addEdge(0, 8);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(7, 8);

    g.printGraph();

    vector<int> eulerCircuit = g.findEulerianPath();

    cout << "Eulerian Circuit: ";
    if (eulerCircuit.empty())
        cout << "None" << endl;
    else
    {
        for (int vertex : eulerCircuit)
            cout << vertex << " ";
        cout << endl;
    }
    return 0;
}
