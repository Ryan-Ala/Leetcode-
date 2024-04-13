class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> Hash;
        for(auto e:strs)
        {
            string tmp =e;
            sort(e.begin(),e.end());
            Hash[e].push_back(tmp);
        }

        vector<vector<string>> ans;
        for(auto &[a,b]:Hash)
        {
            ans.push_back(b);
        }
        return ans;
    }
};