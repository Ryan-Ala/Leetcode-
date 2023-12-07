class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 2, INT_MAX));
        for (int i = 0; i <= matrix.size(); i++)
            dp[0][i] = 0;

        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix.size(); j++)
            {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
            }
        }
        int min = INT_MAX;
        for (int i = 0; i < matrix.size() + 2; i++)
            if (min > dp[matrix.size()][i])
                min = dp[matrix.size()][i];
        return min;
    }
};