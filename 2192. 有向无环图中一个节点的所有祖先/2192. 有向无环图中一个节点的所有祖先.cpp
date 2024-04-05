class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> E = vector<vector<int>>(n);
        vector<int> in = vector<int>(n);
        vector<vector<int>> ans = vector<vector<int>>(n);

        for(auto &e:edges)
        {
            int u = e[0],v=e[1];
            E[u].push_back(v);
            in[v]++;
        }

        queue<int> q;

        unordered_map<int,set<int>> Hash;
        for(int i=0;i<n;i++)
        if(in[i]==0)
        {
            q.push(i);
            ans[i]=vector<int>();
        }

        //vector<bool> visit = vector<int>(n);
        while(q.size())
        {
            int sz=q.size();
            while(sz--)
            {
                auto u = q.front();
                q.pop();

                for(auto &e:E[u])
                {
                    for(auto ee:Hash[u])
                    Hash[e].insert(ee);
                    Hash[e].insert(u);
                    if(--in[e]==0)
                        q.push(e);
                }
            }
        }
        for(int i=0;i<n;i++)
            ans[i]=vector<int>(Hash[i].begin(),Hash[i].end());
        return ans;
    }
};