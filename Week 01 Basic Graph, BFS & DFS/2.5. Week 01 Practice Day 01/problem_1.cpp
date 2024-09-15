#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

vector<int> bfsShortestDistance(int V, const vector<vector<int>> &adj, int start, int end)
{
    vector<int> distance(V, INT_MAX); // Distance from start to each node
    queue<int> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (distance[neighbor] == INT_MAX)
            { // Not visited
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    // Read edges
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    int Q;
    cin >> Q;

    // Process each query
    for (int i = 0; i < Q; ++i)
    {
        int S, D;
        cin >> S >> D;

        vector<int> distances = bfsShortestDistance(V, adj, S, D);

        if (distances[D] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << distances[D] << endl;
        }
    }

    return 0;
}
