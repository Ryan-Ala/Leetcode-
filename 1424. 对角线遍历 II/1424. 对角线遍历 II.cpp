class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> Hash;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                Hash[i+j].push_back(nums[i][j]);  //每一条对角线的 横纵坐标 和相等
            }
        }

        vector<int> ans;
        for(auto& [a,e]:Hash)
        {
            for(int i=e.size()-1;i>=0;i--)
            {
                ans.push_back(e[i]);
            }
        }
        return ans;
    }
};