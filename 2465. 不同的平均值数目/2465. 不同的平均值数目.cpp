class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_set<double> Hash;

        int left=0,right = nums.size()-1;
        while(left<right)
        {
            Hash.insert((nums[right--]+nums[left++])/2.0);
        } 
        return Hash.size();
    }
};