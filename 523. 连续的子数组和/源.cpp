class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, pos;
        unordered_map<int, int> Hash;
        Hash[0] = -1;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            pos = sum % k;
            if (Hash.count(pos))
            {
                if (j - Hash[pos] > 1)
                    return 1;
            }
            else
                Hash[pos] = j;
        }
        return 0;
    }
};