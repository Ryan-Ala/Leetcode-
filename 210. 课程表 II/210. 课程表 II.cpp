class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> in(numCourses),ans;
        int count = prerequisites.size();
        queue<int> q;
        for(auto &e:prerequisites)
        {
            edge[e[1]].push_back(e[0]);
            in[e[0]]++;
        }
       
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
            q.push(i);
        }

        while(q.size())
        {
            int num = q.front();
            q.pop();
            ans.push_back(num);
            for(auto& e:edge[num])
            {
                if(--in[e]==0)
                {
                    q.push(e);
                }
                count--;
            }
        }
        if(count)
        return {};
        return ans;

    }
};