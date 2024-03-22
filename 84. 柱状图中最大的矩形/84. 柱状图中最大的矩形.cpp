class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size();
        int ans=0;
        stack<int> s;
        vector<int> left(m,-1),right(m,m);

        for(int i=0;i<m;i++)
        {
            while(s.size()&&heights[i]<=heights[s.top()])
            s.pop();
            if(s.size())
            left[i]=s.top();
            s.push(i);
        }

        s = stack<int>();
        for(int i=m-1;i>=0;i--)
        {
            while(s.size()&&heights[i]<=heights[s.top()])
            s.pop();
            if(s.size())
            right[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<m;i++)
        {
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};