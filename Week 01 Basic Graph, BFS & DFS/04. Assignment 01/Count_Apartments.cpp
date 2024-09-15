#include <bits/stdc++.h>
using namespace std;

char grid[1001][1001];
bool visited[1001][1001];

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;

bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y]);
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (pair<int, int> direction : directions)
    {
        int new_direction_x = x + direction.first;
        int new_direction_y = y + direction.second;

        if (is_valid(new_direction_x, new_direction_y))
        {
            dfs(new_direction_x, new_direction_y);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}