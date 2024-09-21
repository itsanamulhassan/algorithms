class Solution
{
public:
    int visited[55][55];
    int ans, column, row;
    vector<pair<int, int>> destinations = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int srcI, int srcJ)
    {
        if (srcI >= 0 && srcI < column && srcJ >= 0 && srcJ < row)
            return true;
        else
            return false;
    }

    void dfs(int srcI, int srcJ, vector<vector<int>> &grid)
    {
        visited[srcI][srcJ] = true;
        ans++;

        for (int i = 0; i < 4; i++)
        {
            int childI = srcI + destinations[i].first;
            int childJ = srcJ + destinations[i].second;

            if (valid(childI, childJ) && !visited[childI][childJ] && grid[childI][childJ] == 1)
            {
                dfs(childI, childJ, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        column = grid.size();
        row = grid[0].size();
        int max_value = 0;
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    ans = 0;
                    dfs(i, j, grid);
                    max_value = max(max_value, ans);
                }
            }
        }

        return max_value;
    };
};