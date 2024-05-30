class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s;
        s+=s;
        if(s.substr(1,s.size()-2).find(tmp)!=string::npos)
        return 1;
        return 0;
    }
};