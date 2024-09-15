#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> parents(N, -1);

bool flag = false;

void dfs(int parent)
{
    visited[parent] = true;
    for (auto child : adj[parent])
    {

        if (visited[child] && child != parents[parent])
        {
            flag = true;
        }
        if (!visited[child])
        {
            parents[child] = parent;
            dfs(child);
        }
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < vertices; i++)
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
        cout << "Cycle not found" << endl;
    }

    return 0;
}