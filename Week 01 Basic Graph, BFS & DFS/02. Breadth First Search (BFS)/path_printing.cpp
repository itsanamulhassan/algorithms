#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visited[1005];
int level[1005];
int per[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (auto child : v[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
                per[child] = parent;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src, des;
    cin >> src >> des;

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(per, -1, sizeof(per));

    bfs(src);

    int x = des;
    vector<int> path;

    while (x != -1)
    {
        path.push_back(x);

        x = per[x];
    }

    reverse(path.begin(), path.end());

    for (int val : path)
    {
        cout << val << " ";
    }

    return 0;
}
