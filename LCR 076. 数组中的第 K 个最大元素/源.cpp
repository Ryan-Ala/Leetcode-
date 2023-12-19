class Solution {
public:

    void AdjustDown(vector<int>& nums, int parent, int numsize)
    {
        int child = parent * 2 + 1;
        while (child < numsize)
        {
            if (child + 1 < numsize && nums[child + 1] > nums[child])
            {
                child++;
            }
            if (nums[child] > nums[parent])
            {
                swap(nums[child], nums[parent]);
                parent = child;
                child = child * 2 + 1;
            }
            else
                break;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = (nums.size() - 2) / 2; i > -1; i--)
        {
            AdjustDown(nums, i, nums.size());
        }
        int numsize = nums.size();
        for (int i = nums.size() - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            numsize--;
            AdjustDown(nums, 0, numsize);
        }
        return nums[nums.size() - k];
    }
};