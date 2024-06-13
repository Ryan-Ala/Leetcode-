class Solution {
public:
    string removeDuplicates(string ss) {
        string ans;
        for(auto &e:ss)
        {
            if(ans.size()&&ans.back()==e)
            ans.pop_back();
            else
            ans+=e;
        }
        return ans;
    }
};