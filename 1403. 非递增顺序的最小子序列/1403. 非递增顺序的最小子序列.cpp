class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int sum = 0;
        for(auto e:nums)
        sum+=e;
        int count=0;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
        {
            count+=nums[i];
            sum-=nums[i];
            ans.push_back(nums[i]);
            if(sum<count)
            return ans;
        }
        return ans;
    }
};