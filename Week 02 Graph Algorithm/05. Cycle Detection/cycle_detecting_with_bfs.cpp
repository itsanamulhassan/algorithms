#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
int parent_array[N];
bool flag;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[src] = true;

        for (auto child : adj[node])
        {
            if (visited[child] == true && parent_array[node] != child)
            {
                flag = true;
            }

            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent_array[child] = node;
            }
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

    memset(visited, false, sizeof(visited));
    memset(parent_array, -1, sizeof(parent_array));
    flag = false;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}