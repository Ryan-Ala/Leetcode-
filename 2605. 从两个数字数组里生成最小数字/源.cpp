class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int min_1 = 10, min_2 = min_1;
        int ret[10] = { 0 };

        for (auto& e : nums1)
        {
            ret[e]++;
            if (e < min_1)
                min_1 = e;
        }

        for (auto& e : nums2)
        {
            ret[e]++;
            if (e < min_2)
                min_2 = e;
        }
        for (int i = 0; i < 10; i++)
        {
            if (ret[i] == 2)
                return i;
        }

        return min(min_1 * 10 + min_2, min_1 + min_2 * 10);
    }
};