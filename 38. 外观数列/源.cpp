
class Solution {
    unordered_map<int, string> mem;
    mem[0] = "1";
public:
    string countAndSay(int n) {
        int pos;
        for (pos = n; pos >= 0; pos--)
        {
            if (mem.count(pos))
                break;
        }
        string ret = mem[pos];
        int left = 0, right = 0;
        for (int i = 0; i < n - 1; i++)
        {
            left = 0, right = 0;
            string ans;
            while (right < ret.size())
            {
                if (ret[left] == ret[right])
                    right++;
                else
                {
                    ans += to_string(right - left);  //转换为string
                    ans += ret[left];
                    left = right;
                }
            }
            ans += to_string(right - left);  //转换为string
            ans += ret[left];
            ret = ans;
        }
        if (mem[n].size() == 0)
            mem[n] = ret;
        return ret;
    }
};