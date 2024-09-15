#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<bool> path_visited(N, false);

bool flag = false;

void dfs(int node)
{
    visited[node] = true;
    path_visited[node] = true;

    for (auto child : adj[node])
    {
        if (path_visited[child])
        {
            flag = true;
        }
        if (!visited[child])
        {
            dfs(child);
        }
    }
    path_visited[node] = false;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    // Reading edges
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Resetting flag
    flag = false;

    // Looping through vertices (1-indexed)
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    if (flag)
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "No cycle found" << endl;
    }

    return 0;
}
