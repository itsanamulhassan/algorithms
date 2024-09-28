#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int column, row;
char matrix[N][N];
bool visited[N][N];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int dfs(int x, int y)
{
    if (x < 0 || x >= column || y < 0 || y >= row || visited[x][y] || matrix[x][y] == '-')
    {
        return 0;
    }
    visited[x][y] = true;

    int area = 1;
    for (auto direction : directions)
    {
        area += dfs(x + direction.first, y + direction.second);
    }

    return area;
}

int main()
{
    cin >> column >> row;

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int minimum_area = INT_MAX;
    bool flag = false;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (matrix[i][j] == '.' && !visited[i][j])
            {
                flag = true;
                int area = dfs(i, j);
                minimum_area = min(minimum_area, area);
            }
        }
    }

    if (!flag)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << minimum_area << endl;
    }

    return 0;
}