class Solution
{
public:
    int column, row;
    bool visited[105][105];
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int childI, int childJ)
    {
        if (childI >= 0 && childI < column && childJ >= 0 && childJ < row)
            return true;
        else
            return false;
    }
    bool flag;
    void dfs(int srcI, int srcJ, vector<vector<int>> &grid)
    {
        visited[srcI][srcJ] = true;

        if (srcI == 0 || srcI == column - 1 || srcJ == 0 || srcJ == row - 1)
            flag = false;
        for (int i = 0; i < 4; i++)
        {
            int childI = srcI + directions[i].first;
            int childJ = srcJ + directions[i].second;

            if (valid(childI, childJ) && !visited[childI][childJ] &&
                grid[childI][childJ] == 0)
            {
                dfs(childI, childJ, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        memset(visited, false, sizeof(visited));

        column = grid.size();
        row = grid[0].size();
        int ans = 0;
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if (flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};