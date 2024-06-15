class Solution {
public:
    bool equalFrequency(string word) {
        if(word.size()==2)
        return 1;
        unordered_map<char,int> Hash;
        int count=0;
        for(auto& e:word)
        {
            ++Hash[e];
        }
        
        vector<int>ret;
        for(auto &[a,b]:Hash)
        {
            ret.push_back(b);
        }
        sort(ret.begin(),ret.end());
        int m = ret.size()-1;
        if(m==0||(ret[0]==ret[m-1]&&ret[m]-1==ret[m-1])||(ret[0]==ret[m]&&ret[0]==1)||(ret[1]==ret[m]&&ret[0]==1))
        return 1;
        return 0;
    }
};