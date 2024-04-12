class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int m=nums.size();
        vector<int> left(m),right(m);
        left[0]=nums[0];
        right[m-1]=nums[m-1];
        for(int i=1;i<m;i++)
        left[i]=min(left[i-1],nums[i]);
        
        for(int i=m-2;i>=0;i--)
        right[i]=min(right[i+1],nums[i]);
        
        int ans=INT_MAX;
        for(int i=1;i<m-1;i++)
           if(nums[i]>left[i-1]&&nums[i]>right[i+1])
        ans=min(ans,nums[i]+right[i+1]+left[i-1]);
        
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};