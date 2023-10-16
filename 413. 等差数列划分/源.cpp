class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        int length = nums.size();

        vector<int> dp(length);
        for (int i = 2; i < length; i++)
        {
            //�����ǰλ����ǰ�����ɵȲ����У���ôҲ�� ��ǰ����Ϊ��β�����еȲ����гʵȲ����У�+1�ӵ��ǵ�ǰλ����ǰ�������ʵȲ�����
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }
        return sum;
    }
};