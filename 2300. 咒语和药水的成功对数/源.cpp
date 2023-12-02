class Solution {
public:
    int find(vector<int>& potions, int num, long long success)
    {
        int left = 0, right = potions.size() - 1, mid;
        while (left < right)
        {
            mid = left + (right - left >> 1);
            if ((long long)num * potions[mid] < success)
                left = mid + 1;
            else
                right = mid;
        }
        if ((long long)potions[left] * num >= success)
            return potions.size() - left;
        return 0;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());
        for (int i = 0; i < spells.size(); i++)
        {
            ans[i] = find(potions, spells[i], success);
        }
        return ans;
    }
};