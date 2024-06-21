class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i=0;i<200;i++)
        {
            char ch;
            if(i<strs[0].size())
            ch=strs[0][i];

            for(auto &e:strs)
            {
                if(i<e.size()&&e[i]==ch);
                else
                return ans;
            }
            ans+=ch;
        }
        return "";
    }
};