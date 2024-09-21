class Solution
{
public:
    bool visited[105][105];
    int ans;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int column, row;

    bool valid(int childI, int childJ)
    {
        if (childI >= 0 && childI < column && childJ >= 0 && childJ < row)
            return true;
        else
            return false;
    }
    void dfs(int srcI, int srcJ, vector<vector<int>> &grid)
    {

        visited[srcI][srcJ] = true;

        for (int i = 0; i < 4; i++)
        {
            int childI = srcI + directions[i].first;
            int childJ = srcJ + directions[i].second;

            if (valid(childI, childJ))
            {
                if (grid[childI][childJ] == 0)
                    ans++;
            }
            else
            {
                ans++;
            }

            if (valid(childI, childJ) && !visited[childI][childJ] &&
                grid[childI][childJ] == 1)
            {
                dfs(childI, childJ, grid);
            }
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        memset(visited, false, sizeof(visited));
        ans = 0;
        column = grid.size();
        row = grid[0].size();

        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {

                if (!visited[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};