class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss,tt;
        for(auto &e:s)
        {
            if(ss.size()&&e=='#')
            ss.pop_back();
            else if(e!='#')
            ss.push_back(e);
        }
        for(auto &e:t)
        {
            if(tt.size()&&e=='#')
            tt.pop_back();
            else if(e!='#')
            tt.push_back(e);
        }
        if(ss==tt)
        return 1;
        return 0;
    }
};