class Solution {
    bool Hash[21][21];
    int m, n, ret = 1, res, x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 }, count = 0;
public:
    void dfs(vector<vector<int>>& grid, int ii, int jj)
    {
        if (grid[ii][jj] == 2)
        {
            if (res == ret)
                count++;
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            int i = ii + x[k];
            int j = jj + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != -1 && !Hash[i][j])
            {
                res++;
                Hash[i][j] = 1;
                dfs(grid, i, j);
                Hash[i][j] = 0;
                res--;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int x, y;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                    ret++;
                else if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        Hash[x][y] = 1;
        dfs(grid, x, y);
        return count;
    }
};