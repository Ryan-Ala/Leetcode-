class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int length = costs.size();
        vector<vector<int>> dp(length + 1, vector<int>(3, 0));
        for (int i = 1; i <= length; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i - 1][j];
            }
        }
        return min(dp[length][0], min(dp[length][1], dp[length][2]));
    }
};