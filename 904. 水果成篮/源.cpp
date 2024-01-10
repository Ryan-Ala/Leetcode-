class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> Hash;
        int left = 0, right = 0, max = 0, key = 0;
        while (right < fruits.size())
        {
            if (!Hash.count(fruits[right]))
                key++;

            Hash[fruits[right++]]++;
            while (key > 2)
            {
                Hash[fruits[left++]]--;
                if (Hash[fruits[left - 1]] == 0)
                {
                    key--;
                    Hash.erase(fruits[left - 1]);
                }

            }
            if (max < right - left)
                max = right - left;
            cout << max << " ";
        }
        return max;
    }
};