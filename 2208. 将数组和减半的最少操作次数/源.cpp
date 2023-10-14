class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> que;
        double sum = 0.0, temp;
        for (auto& e : nums)
        {
            que.push(e);
            sum += e;
        }
        int count = 0;
        sum /= 2.0;
        while (sum > 0.0)
        {
            count++;
            temp = que.top() / 2.0;
            que.pop();
            que.push(temp);
            sum -= temp;
        }
        return count;
    }
};