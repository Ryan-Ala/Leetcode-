class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int count=0;
        sort(coins.begin(),coins.end());
        int m = coins.size(),next_coin = 1,now_money = 0,ans=0,i=0;
        while(now_money<target)
        {
            if(i<m&&coins[i]<=next_coin)
            {
                now_money += coins[i++];  // 1 2 3
                next_coin=now_money+1;; //3 4
            }
            else
            {
                now_money+=next_coin; 
                next_coin*=2;  
                ans++;  
            }
        }
        return ans;
    }
};


