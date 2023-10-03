class Solution {
    int count, m, n;
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
    bool Hash[501][501], ret[501][501];
public:
    bool dfs(vector<vector<int>>& grid2, int sr, int sc)
    {
        ret[sr][sc] = 1;
        bool flag = 1;
        if (!Hash[sr][sc])
            flag = 0;
        for (int k = 0; k < 4; k++)
        {
            int i = sr + x[k], j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && grid2[i][j] && !ret[i][j])
            {
                if (!dfs(grid2, i, j))
                    flag = 0;
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid1[i][j])
                    Hash[i][j] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] && !ret[i][j] && Hash[i][j])
                {
                    if (dfs(grid2, i, j))
                        count++;
                }
            }
        return count;
    }
};