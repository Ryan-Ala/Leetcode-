class StockSpanner {
public:
    stack<pair<int,int>> s;
    int pos=0;
    StockSpanner() {
        s.push({INT_MAX,pos});
    }
    
    int next(int price) {
        while(s.size()&&price>=s.top().first)
        {
            s.pop();
        }
        pos++;
        int ans = pos-s.top().second;
        s.push({price,pos});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */