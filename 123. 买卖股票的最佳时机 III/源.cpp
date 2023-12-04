class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f表示第i天有股票                 g表示第i天没有股票
        vector<vector<int>> f(prices.size(), vector<int>(3, -300000)), g(prices.size(), vector<int>(3, -100000));
        f[0][0] = -prices[0];
        g[0][0] = 0;                           //不能设置为最小，否则在做减法时可能越界
        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {           //在买入前和买入后完成的交易都是j笔，所以无需+1或-1
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                if (j == 0)
                    g[i][j] = g[i - 1][j];
                else   //卖出股票后，交易完成的数量+1,所以完成j笔交易时要去f[i-1][j-1]找上一个值
                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
            }
        }
        int max = 0;
        for (int j = 0; j < 3; j++)
            if (g[prices.size() - 1][j] > max)
                max = g[prices.size() - 1][j];
        return max;
    }
};