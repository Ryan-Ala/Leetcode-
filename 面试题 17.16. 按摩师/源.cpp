class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() < 3)
        {
            if (nums.size() == 0)
                return 0;
            if (nums.size() == 1)
                return nums[0];
            if (nums.size() == 2)
                return max(nums[0], nums[1]);
        }
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }
        return nums[nums.size() - 1];
    }
};