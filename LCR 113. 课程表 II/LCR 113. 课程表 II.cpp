class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> edge(numCourses);
        vector<int> in(numCourses);
        for(auto &e:prerequisites)
        {
            edge[e[1]].push_back(e[0]);
            in[e[0]]++;
        }
        int count = prerequisites.size();
        queue<int> q;
        for(int i =0;i<numCourses;i++)
        {
            if(in[i]==0)
            q.push(i);    //寻找起点
        }
        while(q.size())
        {
            int a = q.front();q.pop();
            ans.push_back(a);
            for(auto& e:edge[a])
            {
                if(--in[e]==0)
                {
                    q.push(e);
                }
                count--;
            }
        }
        if(count) return {};
        return ans;
    }
};