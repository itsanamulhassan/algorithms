class Solution
{
public:
    int column, row;
    bool visited[305][305];
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int childI, int childJ)
    {
        if (childI >= 0 && childI < column && childJ >= 0 && childJ < row)
            return true;
        else
            return false;
    }

    void dfs(int srcI, int srcJ, vector<vector<char>> &grid)
    {
        visited[srcI][srcJ] = true;

        for (int i = 0; i < 4; i++)
        {
            int childI = srcI + directions[i].first;
            int childJ = srcJ + directions[i].second;

            if (valid(childI, childJ) && !visited[childI][childJ] &&
                grid[childI][childJ] == '1')
            {
                dfs(childI, childJ, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        column = grid.size();
        row = grid[0].size();
        memset(visited, false, sizeof(visited));
        int ans = 0;

        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};