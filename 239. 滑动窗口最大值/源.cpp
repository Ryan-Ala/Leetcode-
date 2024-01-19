class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> queue;   //优先队列
        for (int i = 0; i < nums.size(); i++)
        {
            while (!queue.empty() && nums[queue.back()] <= nums[i])
            {
                queue.pop_back();
            }
            queue.push_back(i);
            if (queue.front() < i - k + 1)
                queue.pop_front();
            if (i + 1 >= k)
                ans.push_back(nums[queue.front()]);
        }
        return ans;
    }
};