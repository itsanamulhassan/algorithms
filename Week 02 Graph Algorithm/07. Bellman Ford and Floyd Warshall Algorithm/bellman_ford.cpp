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
    }

    for (Edge edge : edges_list)
    {
        cout << edge.u << " " << edge.v << " " << edge.c << endl;
    }

    return 0;
}