class Solution {
    int m, n, xx, yy;
    int x[2] = { 1,0 }, y[2] = { 0,1 };
    vector<vector<int>> ans;
    bool Hash[300][300];
public:
    bool dfs(vector<vector<int>>& obstacleGrid, int sr, int sc)
    {
        if (sr == xx && sc == yy && !obstacleGrid[m - 1][n - 1])
        {
            return 1;
        }
        for (int k = 0; k < 2; k++)
        {
            int i = sr + x[k], j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && !Hash[i][j] && !obstacleGrid[i][j])
            {
                Hash[sr][sc] = 1;
                ans.push_back({ i,j });
                if (dfs(obstacleGrid, i, j))
                    return 1;
                ans.pop_back();
            }
        }
        return 0;
    }
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return ans;
        xx = m - 1;
        yy = n - 1;
        ans.push_back({ 0,0 });
        if (dfs(obstacleGrid, 0, 0))
            return ans;
        return {};
    }
};