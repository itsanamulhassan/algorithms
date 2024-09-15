#include <bits/stdc++.h>
using namespace std;

char grid[1001][1001];
bool visited[1001][1001];
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && (grid[x][y] == '.' || grid[x][y] == 'B') && !visited[x][y]);
}

bool can_go(int start_x, int start_y, int end_x, int end_y)
{

    queue<pair<int, int>> bfs_queue;

    memset(visited, false, sizeof(visited));

    bfs_queue.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!bfs_queue.empty())
    {
        pair<int, int> current = bfs_queue.front();
        int current_x = current.first;
        int current_y = current.second;
        bfs_queue.pop();

        if (current_x == end_x && current_y == end_y)
        {
            return true;
        }

        for (pair<int, int> direction : directions)
        {
            int new_current_x = current_x + direction.first;
            int new_current_y = current_y + direction.second;

            if (is_valid(new_current_x, new_current_y))
            {
                visited[new_current_x][new_current_y] = true;
                bfs_queue.push({new_current_x, new_current_y});
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    if (can_go(start.first, start.second, end.first, end.second))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}