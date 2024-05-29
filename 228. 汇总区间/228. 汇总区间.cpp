class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int m = nums.size();
        vector<string> ans;
        if(m==0)
        return ans;

        int left=nums[0],right=left;
        for(int i=1;i<m;i++)
        {
            if(nums[i]==right+1)
            right=nums[i];
            else
            {
                if(left!=right)
                    ans.push_back(to_string(left)+"->"+to_string(right));
                else
                    ans.push_back(to_string(left));
                left=right=nums[i];
            }
        }
        if(left!=right)
        ans.push_back(to_string(left)+"->"+to_string(right));
        else
        ans.push_back(to_string(left));

        return ans;
    }
};