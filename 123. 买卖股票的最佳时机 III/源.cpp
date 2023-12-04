class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f��ʾ��i���й�Ʊ                 g��ʾ��i��û�й�Ʊ
        vector<vector<int>> f(prices.size(), vector<int>(3, -300000)), g(prices.size(), vector<int>(3, -100000));
        f[0][0] = -prices[0];
        g[0][0] = 0;                           //��������Ϊ��С��������������ʱ����Խ��
        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {           //������ǰ���������ɵĽ��׶���j�ʣ���������+1��-1
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                if (j == 0)
                    g[i][j] = g[i - 1][j];
                else   //������Ʊ�󣬽�����ɵ�����+1,�������j�ʽ���ʱҪȥf[i-1][j-1]����һ��ֵ
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