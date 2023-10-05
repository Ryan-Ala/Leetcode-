class Solution {
    int m, n;
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
    bool Hash_1[201][201], Hash_2[201][201];
    vector<vector<int>> ans;
public:
    void dfs(vector<vector<int>>& heights, int sr, int sc, bool(&Hash)[201][201])
    {
        Hash[sr][sc] = 1;
        for (int k = 0; k < 4; k++)
        {
            int i = sr + x[k], j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && !Hash[i][j] && heights[i][j] >= heights[sr][sc])
                dfs(heights, i, j, Hash);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        for (int i = 0; i < m; i++)
        {
            if (!Hash_1[i][0]) dfs(heights, i, 0, Hash_1);
            if (!Hash_2[i][n - 1]) dfs(heights, i, n - 1, Hash_2);
        }

        for (int j = 0; j < n; j++)
        {
            if (!Hash_1[0][j]) dfs(heights, 0, j, Hash_1);
            if (!Hash_2[m - 1][j]) dfs(heights, m - 1, j, Hash_2);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (Hash_1[i][j] && Hash_2[i][j])
                    ans.push_back({ i,j });
            }
        return ans;
    }
};