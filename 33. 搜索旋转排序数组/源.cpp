class Solution {
public:
    int find(vector<int>& nums, int begin, int end, int target)
    {
        if (begin > end) return -1;
        while (begin < end)
        {
            int mid = (end + begin) >> 1;
            if (nums[mid] < target)
                begin = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                return mid;
        }
        return nums[begin] == target ? begin : -1;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right + left) >> 1;
            if (nums[mid] < nums[nums.size() - 1])
                right = mid;
            else
                left = mid + 1;
        }

        int ans = -1;

        if (nums[0] <= target)
            ans = find(nums, 0, left - 1, target);
        if (ans != -1)
            return ans;

        if (nums[nums.size() - 1] >= target)
            ans = find(nums, left, nums.size() - 1, target);

        return ans;

    }
};