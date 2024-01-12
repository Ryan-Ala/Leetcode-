class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string ret = "croak";
        int length = croakOfFrogs.size();
        unordered_map<char, int> Hash;

        vector<int> res(ret.size());

        for (int i = 0; i < ret.size(); i++)
            Hash[ret[i]] = i;

        for (int i = 0; i < length; i++)
        {
            if (croakOfFrogs[i] == 'c')
            {
                if (res[res.size() - 1] > 0)
                    res[res.size() - 1]--;
                res[0]++;
            }
            else
            {
                int k = Hash[croakOfFrogs[i]];
                if (res[k - 1] == 0)
                    return -1;
                else
                {
                    res[k]++;
                    res[k - 1]--;
                }
            }
        }
        for (int i = 0; i < res.size() - 1; i++)
        {
            if (res[i] != 0)
                return -1;
        }
        return res[res.size() - 1];
    }
};