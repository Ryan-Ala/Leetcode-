class Solution {
public:
    unordered_map<char,unordered_set<char>> Hash;
    unordered_map<char,int> in;
    
    bool Add(string& a,string& b)
    {
        bool flag=0;
        int m = min(a.size(),b.size()),i;
        for(i=0;i<m;i++)
        {
            if(a[i]!=b[i])
            {
                flag = 1;
                if(!Hash.count(a[i])||!Hash[a[i]].count(b[i]))
                in[b[i]]++;
                Hash[a[i]].insert(b[i]);
                break;
            }
        }
        if(!flag&&m<a.size())
        return 1;
        return 0;
    }

    string alienOrder(vector<string>& words) {
        
        int m = words.size();
        for(auto &e:words)
        {
            for(auto &ee:e)
            in[ee]=0;
        }

        for(int i=0;i<m;i++)
        {
            for(int j = i;j<m;j++)
            {
                if(Add(words[i],words[j]))
                return "";
            }
        }

        string ans;
        queue<char> q;
        for(auto &[a,b]:in)
        {
            if(b==0)
            q.push(a);
        }
        while(q.size())
        {
            auto a = q.front();
            q.pop();
            ans+=a;
            for(auto &ret:Hash[a])
            {
                if(--in[ret]==0)
                q.push(ret);
            }
        }
        for(auto &[a,b]:in)
        if(b)return "";

        return ans;
    }
};