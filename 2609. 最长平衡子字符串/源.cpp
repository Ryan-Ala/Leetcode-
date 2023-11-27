class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int max_num = 0, n = s.size();
        int i = 0;
        while (i < n)
        {
            int ret = 0, res = 0;
            while (i < n && s[i] == '1')
                i++;
            while (i < n && s[i] == '0')
            {
                i++;
                ret++;
            }
            while (i < n && s[i] == '1')
            {
                res++;
                i++;
            }
            if (ret <= res)
            {
                max_num = max(2 * ret, max_num);
            }
            else
            {
                max_num = max(max_num, 2 * res);
            }
        }
        return max_num;
    }
};