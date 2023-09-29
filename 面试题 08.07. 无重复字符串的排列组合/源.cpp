lass Solution{
    vector<string> ans;
    string ret;
    unordered_map<char,bool> Hash;
public:
    void dfs(string& S)
    {
        if (ret.size() == S.size())
        {
            ans.push_back(ret);
            return;
        }
        for (auto& e : S)
        {
            if (Hash[e] == 0)
            {
                Hash[e] = 1;
                ret.push_back(e);
                dfs(S);
                ret.pop_back();
                Hash[e] = 0;
            }
        }
    }
    vector<string> permutation(string S) {
        for (auto& e : S)
        Hash[e] = 0;
        dfs(S);
        return ans;
    }
};