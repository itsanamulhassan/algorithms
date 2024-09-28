#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int grp_size[N], parents[N];

class Edge
{
public:
    long long int u, v, w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void dsu_initialization(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        parents[i] = -1;
        grp_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parents[node] == -1)
    {
        return node;
    }
    parents[node] = dsu_find(parents[node]);
    return parents[node];
}

void dsu_union_by_size(int node1, int node2)
{
    int leader_a = dsu_find(node1), leader_b = dsu_find(node2);

    if (leader_a != leader_b)
    {
        if (grp_size[leader_a] < grp_size[leader_b])
        {
            grp_size[leader_b] += grp_size[leader_a];
            parents[leader_a] = leader_b;
        }
        else
        {
            grp_size[leader_a] += grp_size[leader_b];
            parents[leader_b] = leader_a;
        }
    }
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<Edge> my_edges;

    for (int i = 0; i < edges; i++)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        my_edges.push_back(Edge(u, v, w));
    }

    dsu_initialization(vertices);

    sort(my_edges.begin(), my_edges.end(), cmp);

    long long int total_cost = 0, edges_used = 0;

    for (Edge edge : my_edges)
    {
        int leader_u = dsu_find(edge.u), leader_v = dsu_find(edge.v);
        if (leader_u != leader_v)
        {
            dsu_union_by_size(edge.u, edge.v);
            total_cost += edge.w;
            edges_used++;
        }
    }

    if (vertices - 1 != edges_used)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << total_cost << endl;
    }

    return 0;
}