class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (int i = 0; i < operations.size(); i++)
        {
            int x = gem[operations[i][0]] / 2;
            gem[operations[i][1]] += x;
            gem[operations[i][0]] -= x;
        }
        int max_num = INT_MIN, min_num = INT_MAX;
        for (int i = 0; i < gem.size(); i++)
        {
            max_num = max(gem[i], max_num);
            min_num = min(gem[i], min_num);
        }
        return max_num - min_num;
    }
};