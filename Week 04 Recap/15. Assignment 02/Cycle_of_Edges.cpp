#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parents[N], grp_size[N];
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
    return parents[node] = dsu_find(parents[node]);
}

void dsu_union_by_size(int node1, int node2)
{
    int leader_a = dsu_find(node1), leader_b = dsu_find(node2);

    if (leader_a != leader_b)
    {
        if (grp_size[leader_a] <= grp_size[leader_b])
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

int main()
{
    int vertices, edges, edges_cycle = 0;

    cin >> vertices >> edges;

    dsu_initialization(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        int leader_u = dsu_find(u), leader_v = dsu_find(v);

        if (leader_u != leader_v)
        {
            dsu_union_by_size(u, v);
        }
        else
        {
            edges_cycle++;
        }
    }

    cout << edges_cycle << endl;

    return 0;
}