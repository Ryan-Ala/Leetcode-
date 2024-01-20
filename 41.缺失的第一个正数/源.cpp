class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (auto& e : nums)
        {
            if (e <= 0)
                e = size + 1;
        }
        int tmp;
        for (auto& e : nums)
        {
            tmp = abs(e);
            if (tmp > 0 && tmp <= size && nums[tmp - 1] > 0)
                nums[tmp - 1] *= -1;
        }
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return size + 1;
    }
};