class Solution {
    int max_num, count, m, n;
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
    bool Hash[51][51];
public:
    void dfs(vector<vector<int>>& grid, int sr, int sc)
    {
        Hash[sr][sc] = 1;
        max_num = max(max_num, ++count);
        for (int k = 0; k < 4; k++)
        {
            int i = sr + x[k], j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && !Hash[i][j] && grid[i][j] == 1)
                dfs(grid, i, j);
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (!Hash[i][j] && grid[i][j] == 1)
                {
                    count = 0;
                    dfs(grid, i, j);
                }
            }
        return max_num;
    }
};