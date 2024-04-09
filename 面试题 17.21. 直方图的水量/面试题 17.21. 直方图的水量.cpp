class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>s;
        int m = height.size();
        int ans = 0;

        // 横向计算面积
        for(int i=0;i<m;i++)
        {
            while(s.size()&&height[i]>=height[s.top()])
            {
                int bottom = height[s.top()];  //底部高度
                s.pop();
                if(s.size()==0)
                break;
                int left = s.top();
                ans+=(min(height[left],height[i])-bottom)*(i-left-1);
            }
            s.push(i);
        }
        return ans;
    }
};