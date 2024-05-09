class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(auto &e:nums)
        if(e==0)
        e=-1;

        int m = nums.size();
        unordered_map<int,int> Hash;
        Hash[0]=-1;
        int ans = 0,count=0;
        for(int i=0;i<m;i++)
        {
            count+=nums[i];
            if(Hash.count(count))
            {
                ans=max(ans,i-Hash[count]);
            }
            else
            Hash[count]=i;
        }
        return ans;
    }
};