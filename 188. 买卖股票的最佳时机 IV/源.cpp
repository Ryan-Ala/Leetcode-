lass Solution{
public:
    int maxProfit(int k, vector<int>&prices) {
        int length = prices.size();
        vector<vector<int>> f(length,vector(k + 1,-1000000));
        auto g = f;
        f[0][0] = -prices[0];
        g[0][0] = 0;

        for (int i = 1; i < length; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                f[i][j] = max(f[i - 1][j],g[i - 1][j] - prices[i]);
                if (j >= 1)
                g[i][j] = max(g[i - 1][j],f[i - 1][j - 1] + prices[i]);
                else
                g[i][j] = g[i - 1][j];
            }
        }
        int max = 0;
        for (int j = 0; j <= k; j++)
        {
            if (max < g[length - 1][j])
            max = g[length - 1][j];
        }
        return max;
    }
};