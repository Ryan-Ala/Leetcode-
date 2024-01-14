class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, sum1 = 0;

        for (auto& e : nums)
            sum += e;

        int left = 0, right = 0, target = sum - x, min = INT_MAX;
        if (target < 0)
            return -1;
        while (right < nums.size())
        {
            sum1 += nums[right];
            while (sum1 > target)
                sum1 -= nums[left++];
            if (sum1 == target)
            {
                int pos = nums.size() - (right - left + 1);  //计算俩下标间的个数要+1
                if (min > pos)
                    min = pos;
            }
            right++;
        }
        if (min == INT_MAX)
            return -1;
        return min;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, sum1 = 0;

        for (auto& e : nums)
            sum += e;

        int left = 0, right = 0, target = sum - x, min = INT_MAX;
        if (target < 0)
            return -1;
        while (right < nums.size())
        {
            sum1 += nums[right];
            while (sum1 > target)
                sum1 -= nums[left++];
            if (sum1 == target)
            {
                int pos = nums.size() - (right - left + 1);  //计算俩下标间的个数要+1
                if (min > pos)
                    min = pos;
            }
            right++;
        }
        if (min == INT_MAX)
            return -1;
        return min;
    }
};
