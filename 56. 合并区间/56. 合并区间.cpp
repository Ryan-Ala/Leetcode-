class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        return {};
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        int left = intervals[0][0],right=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            int l=intervals[i][0],r=intervals[i][1];
            if(right>=l)
            {
                right=max(right,r);
            }
            else
            {
                ans.push_back({left,right});
                left=l;
                right=r;
            }
        }
        ans.push_back({left,right});
        return ans;
    }
};