class Solution {
public:
    string capitalizeTitle(string title) {

        stringstream ss;
        ss<<title;
        string s,ans;
        while(ss>>s)
        {
            if(s.size()>2)
            {
                fun(s);
            }
            else
            {
                fun_1(s);
            }
            ans+=s+" ";
        }
        return ans.substr(0,ans.size()-1);
    }

    void fun(string& s)
    {
        for(auto &e:s)
        if(e<='Z'&&e>='A')
        e+=32;
        s[0]-=32;
    }

    void fun_1(string& s)
    {
        for(auto &e:s)
        if(e<='Z'&&e>='A')
        e+=32;
    }
};