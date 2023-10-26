class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ret;
        for (auto& e : nums)
            ret[e]++;
        int count;
        for (auto [i, val] : ret)
            if (ret.count(i + 1))
                count = max(count, val + ret[i + 1]);

        return count;
    }
};