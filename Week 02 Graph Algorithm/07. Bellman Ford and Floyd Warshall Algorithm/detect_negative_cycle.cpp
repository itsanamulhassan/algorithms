#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e5 + 5;
vector<long int> distances(N, INT_MAX);
int main()
{

    int vertices, edges;
    cin >> vertices >> edges;
    vector<Edge> edges_list;
    while (edges--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges_list.push_back(Edge(u, v, c));
        edges_list.push_back(Edge(v, u, c)); // for undirected graph
    }
    distances[0] = 0;
    for (int i = 1; i <= vertices - 1; i++)
    {
        for (Edge edge : edges_list)
        {
            int u = edge.u, v = edge.v, c = edge.c;

            if (distances[u] < INT_MAX && distances[u] + c < distances[v])
            {
                distances[v] = distances[u] + c;
            }
        }
    }

    bool flag = false;
    for (Edge edge : edges_list)
    {
        int u = edge.u, v = edge.v, c = edge.c;

        if (distances[u] < INT_MAX && distances[u] + c < distances[v])
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "Cycle found. No answer" << endl;
    }
    else
    {

        for (int i = 0; i < vertices; i++)
        {

            cout << i << " --> " << distances[i] << endl;
        }
    }
    return 0;
}