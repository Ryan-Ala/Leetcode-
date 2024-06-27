class Solution {
public:
    string reorganizeString(string s) {
        char ch;
        int max_count=0;
        unordered_map<int,int> Hash;
        int m = s.size();
        for(auto& e:s)
        {
            int a = ++Hash[e];
            if(a>max_count)
            {
                max_count=a;
                ch=e;
            }
        }
        if(max_count>(m+1)/2)return "";
        vector<char> ans(m);
        int pos=0;
        string anss;
        while(max_count--)
        {
            ans[pos]=ch;
            pos+=2;
        }
        Hash.erase(ch);
        for(auto [a,b]:Hash)
        {
            while(b--)
            {
                if(pos>=m)
                pos=1;
                ans[pos]=a;
                pos+=2;
                
            }
        }
        
        for(auto& e:ans)
        {
            anss+=e;
        }
        return anss;
    }
};