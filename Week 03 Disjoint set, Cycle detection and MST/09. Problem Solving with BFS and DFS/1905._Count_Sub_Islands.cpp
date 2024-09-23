class Solution
{
public:
    int column, row;
    bool visited[505][505];

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int childI, int childJ)
    {
        if (childI >= 0 && childI < column && childJ >= 0 && childJ < row)
            return true;
        else
            return false;
    }
    bool flag;
    void dfs(int srcI, int srcJ, vector<vector<int>> &grid1,
             vector<vector<int>> &grid2)
    {
        visited[srcI][srcJ] = true;
        if (grid1[srcI][srcJ] == 0)
            flag = false;

        for (int i = 0; i < 4; i++)
        {
            int childI = srcI + directions[i].first;
            int childJ = srcJ + directions[i].second;

            if (valid(childI, childJ) && !visited[childI][childJ] &&
                grid2[childI][childJ] == 1)
            {

                dfs(childI, childJ, grid1, grid2);
            }
        }
    }

    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2)
    {
        memset(visited, false, sizeof(visited));

        column = grid2.size();
        row = grid2[0].size();
        int ans = 0;

        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (!visited[i][j] && grid2[i][j] == 1)
                {
                    flag = true;
                    dfs(i, j, grid1, grid2);
                    if (flag == true)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};