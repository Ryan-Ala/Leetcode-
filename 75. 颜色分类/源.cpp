class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, left = -1, right = nums.size();
        while (i < right)  //0-left Ϊ0    left+1 - right 1   right - nums.size() Ϊ 2
        {
            if (nums[i] == 0)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == 1)
                i++;
            else
                swap(nums[--right], nums[i]);
        }
    }
};