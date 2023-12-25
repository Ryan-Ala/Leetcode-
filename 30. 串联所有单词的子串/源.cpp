class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> Hash;
        vector<int> ans;
        for (auto& e : words)
            Hash[e]++;   //默认初始化为0

        int word_length = words[0].size(), length = words.size(), size = length * word_length, left, right, count = 0;
        string in;
        for (int i = 0; i < word_length; i++)
        {
            unordered_map<string, int> ret;
            left = right = i;
            count = 0;
            while (right + word_length <= s.size())
            {
                in = s.substr(right, word_length);
                right += word_length;
                if (Hash.count(in) && ++ret[in] <= Hash[in])
                    count++;
                if (right - left > size)
                {
                    in = s.substr(left, word_length);
                    if (Hash.count(in) && ret[in]-- <= Hash[in])
                        count--;
                    left += word_length;
                }
                if (count == length)
                    ans.push_back(left);
            }
        }
        return ans;
    }
};