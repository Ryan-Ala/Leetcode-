class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> ret(length);
        for (int i = 0; i < length; i++)
        {
            for (auto& e : words[i])
                ret[i] |= (1 << (e - 'a'));
        }
        int max_num = 0;
        for (int i = 0; i < length - 1; i++)
            for (int j = i + 1; j < length; j++)
            {
                if ((ret[i] & ret[j]) == 0)
                    max_num = max(max_num, (int)(words[i].size() * words[j].size()));
            }
        return max_num;
    }
};