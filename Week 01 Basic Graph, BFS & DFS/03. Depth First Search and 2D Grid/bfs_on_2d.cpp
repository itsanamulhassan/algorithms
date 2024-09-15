#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
int distnc[100][100];
char a[100][100];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

vector<int> v[100];

int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)

        return false;

    return true;
}

void bfs(int srcI, int srcJ)
{
    queue<pair<int, int>> q;
    q.push({srcI, srcJ});

    vis[srcI][srcJ] = true;
    distnc[srcI][srcJ] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        // cout << parent.first << " " << parent.second << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;

            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                distnc[ci][cj] = distnc[parent.first][parent.second] + 1;
            }
        }
    }
};
int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(distnc, -1, sizeof(distnc));
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);

    cout << distnc[2][3];

    return 0;
}