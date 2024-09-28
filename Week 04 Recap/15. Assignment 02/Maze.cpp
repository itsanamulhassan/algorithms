#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int column, row, str_x, str_y;
char matrix[N][N];
bool visited[N][N];
pair<int, int> parents[1005][1005];

vector<pair<int, int>>
    directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int child_x = parent.first, child_y = parent.second;
        q.pop();

        if (matrix[child_x][child_y] == 'D')
        {

            while (matrix[child_x][child_y] != 'R')
            {
                pair<int, int> previous = parents[child_x][child_y];
                if (matrix[child_x][child_y] != 'D')
                {
                    matrix[child_x][child_y] = 'X';
                }
                child_x = previous.first;
                child_y = previous.second;
            }
            return;
        }

        for (pair<int, int> direction : directions)
        {
            int new_x = child_x + direction.first, new_y = child_y + direction.second;

            if (new_x >= 0 && new_x < column && new_y >= 0 && new_y < row && !visited[new_x][new_y] && (matrix[new_x][new_y] == '.' || matrix[new_x][new_y] == 'D'))
            {
                visited[new_x][new_y] = true;
                parents[new_x][new_y] = {child_x, child_y};
                q.push({new_x, new_y});
            }
        }
    }
}

int main()
{
    cin >> column >> row;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'R')
            {
                str_x = i;
                str_y = j;
            }
        }
    }

    bfs(str_x, str_y);

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}