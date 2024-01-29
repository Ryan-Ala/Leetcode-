class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<int> ret(grid.size(), INT_MAX);
        vector<int>::iterator it = grid[0].begin();
        for (int i = 0; it != grid[0].end(); i++, it++)
            ret[i] = *it;
        int n = grid.size(), res, min;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = ret[j];
                min = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (k == j)
                        continue;
                    min = fmin(min, grid[i][k]);
                }
                ret[j] += min;
            }
        }
        min = ret[0];
        for (auto e : ret)
        {
            min = fmin(min, e);
        }
        return min;
    }
};