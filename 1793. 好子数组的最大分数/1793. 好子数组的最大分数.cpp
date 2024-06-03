class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int m = nums.size();
        vector<int> left(m,-1),right(m,m);  //left数组最小下标为0,right数组最小下标为m-1  
        //所以设置时为-1和m

        //寻找当前数的左侧第一个比其小的数
        stack<int> s;
        for(int i=0;i<m;i++)
        {
            while(s.size()&& nums[s.top()] >=nums[i])
            s.pop();
            if(s.size())
            left[i]=s.top();
            s.push(i);
        }

        //寻找当前数的右侧第一个比其小的数
        s = stack<int>();
        for(int i=m-1;i>=0;i--)
        {
            while(s.size()&& nums[i]<=nums[s.top()] )
            s.pop();
            if(s.size())
            right[i]=s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0;i<m;i++)   //枚举 i ,寻找一个范围,该范围中 i是最小的数 ,那么此时就需要单调栈来优化了
        {
            int l = left[i],r = right[i];  //寻找出来后，再判断是否合法
            if(l<k&&k<r)  //题目规定下标为k处的数必须在数组内，这里如果等于 k ,那么小于当前nums[i]的数是下标k处,
            //可以此时是不包含下标k在内的 因为这里取数组的范围为 [l+1,r-1] 的位置，不包含 l与r
            ans=max(ans,nums[i]*(r-l-1));
        }
        return ans;
    }
};