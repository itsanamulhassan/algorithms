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

int connected_dfs(int x, int y)
{
    visited[x][y] = true;
    int count = 1;

    for (pair<int, int> direction : directions)
    {
        int new_direction_x = x + direction.first;
        int new_direction_y = y + direction.second;

        if (is_valid(new_direction_x, new_direction_y))
        {
            count += connected_dfs(new_direction_x, new_direction_y);
        }
    }

    return count;
}

vector<int> count_apartments()
{
    vector<int> apartments_list;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int count = connected_dfs(i, j);
                apartments_list.push_back(count);
            }
        }
    }

    if (!apartments_list.empty())
    {
        sort(apartments_list.begin(), apartments_list.end());
    }
    else
    {
        apartments_list.push_back(0);
    }

    return apartments_list;
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

    vector<int> apartments_number = count_apartments();

    for (int apartment : apartments_number)
    {
        cout << apartment << " ";
    }

    return 0;
}
