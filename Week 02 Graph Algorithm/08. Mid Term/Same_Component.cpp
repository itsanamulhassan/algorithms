#include <iostream>
#include <vector>

using namespace std;
const int CONST_N = 1005;
const int CONST_M = 1005;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<vector<bool>> visited(CONST_N, vector<bool>(CONST_M, false));

void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '-' || visited[i][j])
    {
        return;
    }

    visited[i][j] = true;

    for (pair<int, int> direction : directions)
    {
        dfs(grid, i + direction.first, j + direction.second);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;

    dfs(grid, Si, Sj);

    if (visited[Di][Dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}