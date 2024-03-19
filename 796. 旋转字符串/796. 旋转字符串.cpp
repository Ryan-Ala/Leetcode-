class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.size(),n=goal.size();
        if(m!=n)return 0;
        if(s==goal)return 1;
        for(int i=1;i<m;i++)
        {
            string ret=s;
            reverse(ret.begin(),ret.begin()+i);
            reverse(ret.begin()+i,ret.end());
            reverse(ret.begin(),ret.end());
            if(ret==goal)
            return 1;
        }
        return 0;

    }
};

//debae
