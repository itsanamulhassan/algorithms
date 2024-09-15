#include <bits/stdc++.h>

using namespace std;

void print_connected_nodes(vector<vector<int>> &graph)
{
    int x;
    cin >> x;

    if (!graph[x].empty())
    {
        sort(graph[x].begin(), graph[x].end(), greater<int>());
        for (int child : graph[x])
        {
            cout << child << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes);

    for (int i = 0; i < edges; ++i)
    {
        int node_a, node_b;
        cin >> node_a >> node_b;
        graph[node_a].push_back(node_b);
        graph[node_b].push_back(node_a);
    }

    int query;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        print_connected_nodes(graph);
    }

    return 0;
}