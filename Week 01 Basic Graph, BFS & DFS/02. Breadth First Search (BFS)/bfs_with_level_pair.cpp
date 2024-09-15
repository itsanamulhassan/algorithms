#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visited[1005];

void bfs(int src, int destination)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;

    bool flag = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int parent = p.first;
        int level = p.second;
        q.pop();
        // cout << parent << endl;

        if (parent == destination)
        {
            cout << level << endl;
            flag = true;
        }

        // for (int i = 0; i < v[parent].size(); i++)
        // {
        //     int child = v[parent][i];
        //     cout << child << endl;
        // }
        for (auto child : v[parent])
        {
            if (visited[child] == false)
            {
                q.push({child, level + 1});
                visited[child] = true;
            }
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
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

    int src;
    cin >>
        src;
    memset(visited, false, sizeof(visited));

    bfs(src, 6);

    return 0;
}