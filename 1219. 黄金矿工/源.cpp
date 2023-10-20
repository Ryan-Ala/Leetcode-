class Solution {
    int m, n, max_sum, x[4] = { 0,0,-1,1 }, y[4] = { 1,-1,0,0 };
    bool Hash[16][16];
public:
    void dfs(vector<vector<int>>& grid, int ii, int jj, int sum)
    {
        max_sum = max(max_sum, sum);
        for (int k = 0; k < 4; k++)
        {
            int i = ii + x[k];
            int j = jj + y[k];
            if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] && !Hash[i][j])
            {
                Hash[i][j] = 1;
                dfs(grid, i, j, sum + grid[i][j]);
                Hash[i][j] = 0;
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    Hash[i][j] = 1;
                    dfs(grid, i, j, grid[i][j]);
                    Hash[i][j] = 0;
                }
            }
        return max_sum;
    }
};