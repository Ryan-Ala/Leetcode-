class Solution {
public:
    int fum(int num)
    {
        int size = 0;
        while (num)
        {
            size++;
            num /= 10;
        }
        return size;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            sum += nums[left] * pow(10, fum(nums[right])) + nums[right];
            left++;
            right--;
        }
        if (left == right)
            sum += nums[right];
        return sum;
    }
};