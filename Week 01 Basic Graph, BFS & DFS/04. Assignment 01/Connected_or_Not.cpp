#include <iostream>
#include <vector>

using namespace std;

bool is_connected(const vector<vector<int>> &my_graph)
{
    int node_a, node_b;
    cin >> node_a >> node_b;

    if (node_a == node_b)
    {
        return true;
    }

    for (int child : my_graph[node_a])
    {
        if (child == node_b)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes);

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int query;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        if (is_connected(graph))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
