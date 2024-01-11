class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        int p1 = 0, p2 = 0, length_1 = nums1.size(), length_2 = nums2.size();
        int n1[2001] = { 0 }, n2[2001] = { 0 };
        for (auto& e : nums1)
            n1[e + 1000] = 1;
        for (auto& e : nums2)
            n2[e + 1000] = 1;

        for (int i = 0; i < 2001; i++)
        {
            if ((!n1[i] && !n2[i]) || (n1[i] && n2[i]))
                continue;
            else
            {
                if (n1[i] == 1)
                    ans[0].push_back(i - 1000);
                else
                    ans[1].push_back(i - 1000);
            }
        }
        return ans;

    }
};