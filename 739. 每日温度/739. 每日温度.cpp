class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int m=temperatures.size();
        vector<int> ans(m,0);
        for(int i=m-1;i>=0;i--)
        {
            while(s.size()&& temperatures[s.top()]<=temperatures[i])
            s.pop();
            if(s.size())
            {
                ans[i]=s.top()-i;
            }
            s.push(i);
        }
        return ans;
    }
};