class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<3)
        {
            if(n==1)
            return {0};
            return {0,1};
        }
        vector<vector<int>> edge = vector<vector<int>>(n);
        vector<int> out=vector<int>(n); //出度数组
        vector<bool> Hash = vector<bool>(n);
        vector<int> ans;

        for(auto &e:edges)
        {
            int a=e[0],b=e[1];
            edge[a].push_back(b);
            edge[b].push_back(a);
            out[b]++;
            out[a]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(out[i]==1)
            q.push(i);
        }
        
        int count=0;
        vector<int> ress;
        while(q.size())
        {
            vector<int> res;
            int sz = q.size();
            count++;
            while(sz--)
            {
                auto num = q.front();
                q.pop();
                for(auto &e:edge[num])
                {
                    int v = e;
                    out[v]--;
                    if(out[v]==1)
                    {
                        res.push_back(v);
                        q.push(v);
                    }
                }
            }
            ans = ress;
            ress = res;
        }
        return ans;
    }
};