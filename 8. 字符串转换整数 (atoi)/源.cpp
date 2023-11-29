class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        bool flag = 0;
        while (i < n && s[i] == ' ')
            i++;
        if (s[i] == '-')
        {
            flag = 1;
            i++;
        }
        else if (s[i] == '+')
            i++;

        long long ans = 0;
        while (i < n && ans <= INT_MAX && ans >= INT_MIN && s[i] >= '0' && s[i] <= '9')
        {
            ans *= 10;
            ans += s[i] - '0';
            i++;
        }
        if (flag)
            ans *= -1;
        if (ans >= INT_MAX)
            return INT_MAX;
        else if (ans <= INT_MIN)
            return INT_MIN;
        return ans;


    }
};