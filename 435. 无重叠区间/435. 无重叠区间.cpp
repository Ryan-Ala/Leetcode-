class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        return {};

        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });

        int count=1,ret=intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(ret>intervals[i][0])
                ret=min(ret,intervals[i][1]);
            else 
            {
                count++;
                ret=intervals[i][1];
            }
        
        }
        return intervals.size()-count;
    }
};