class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> Hash;
        for(auto e:arr)
        Hash[e]++;

        unordered_set<int> Hash1;

        for(auto [a,e]:Hash)
        if(Hash1.count(e))
        return 0;
        else
        Hash1.insert(e);

        return 1;
    }
};