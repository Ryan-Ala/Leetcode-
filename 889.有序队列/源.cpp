class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        int n = s.size();
        string min = s;
        for (int i = 0; i < n; i++)
        {
            char ss = s[0];
            s = s.substr(1);
            s.push_back(ss);
            if (s < min)
                min = s;
        }
        return min;

    }
};