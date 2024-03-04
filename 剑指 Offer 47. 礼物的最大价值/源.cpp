class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> ret(grid.size(), vector<int>(grid[0].size(), 0));

        ret[0][0] = grid[0][0];

        for (int i = 1; i < grid[0].size(); i++)
            ret[0][i] = ret[0][i - 1] + grid[0][i];

        for (int i = 1; i < grid.size(); i++)
            ret[i][0] = ret[i - 1][0] + grid[i][0];

        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                ret[i][j] = max(ret[i][j - 1], ret[i - 1][j]) + grid[i][j];
            }
        }
        return ret[grid.size() - 1][grid[0].size() - 1];
    }
};