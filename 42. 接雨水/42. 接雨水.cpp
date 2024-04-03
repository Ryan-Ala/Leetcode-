class Solution {
public:
    int trap(vector<int>& height) {
        int m = height.size();
       // stack<int> s;
        vector<int> left(m,-1),right(m,m);

        left[0]=height[0];
        for(int i=1;i<m;i++)
        left[i]=max(left[i-1],height[i]);

        right[m-1]=height[m-1];
        for(int i=m-2;i>=0;i--)
        right[i]=max(right[i+1],height[i]);


        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};

/* class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) 
        {
            while (!st.empty() && height[i] >= height[st.top()]) 
            {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) 
                {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], height[i]) - bottom_h; // 面积的高
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};。 */