class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> Hash;
        int i = 0;
        for (auto& e : nums)
        {
            if (Hash.count(e) && abs(Hash[e] - i) <= k)
                return 1;
            Hash[e] = i++;
        }
        return 0;
    }
};