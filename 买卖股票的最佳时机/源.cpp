lass Solution{
public:
    int maxProfit(vector<int>&prices) {
        int min_price = INT_MAX,max_price = 0;

        for (int i = 0; i < prices.size(); i++)
        {   //ѭ���ҳ���Сֵ
            if (prices[i] < min_price)
            min_price = prices[i];
            if (max_price < prices[i] - min_price)  //ÿ�ζ����бȽϣ�������ó����ֵ
            max_price = prices[i] - min_price;
        }
        return max_price;
    }
};