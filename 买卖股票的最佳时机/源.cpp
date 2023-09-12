lass Solution{
public:
    int maxProfit(vector<int>&prices) {
        int min_price = INT_MAX,max_price = 0;

        for (int i = 0; i < prices.size(); i++)
        {   //循环找出最小值
            if (prices[i] < min_price)
            min_price = prices[i];
            if (max_price < prices[i] - min_price)  //每次都进行比较，并计算得出最大值
            max_price = prices[i] - min_price;
        }
        return max_price;
    }
};