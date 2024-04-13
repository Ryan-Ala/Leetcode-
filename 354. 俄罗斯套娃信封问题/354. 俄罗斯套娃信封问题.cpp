class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];
        });

        int length = envelopes.size();
        vector<int> ret;
        ret.push_back(envelopes[0][1]);

        for(int i=1;i<length;i++)
        {
            int tmp=envelopes[i][1];
            if(tmp>ret.back())
            {
                ret.push_back(tmp);
            }
            else 
            {
                int mid,left=0,right=ret.size()-1;
                while(left<right)
                {
                    mid=left+(right-left>>1);
                    if(ret[mid]>=tmp)
                    right=mid;
                    else
                    left=mid+1;
                }
                ret[left]=tmp;
            }
        }
        return ret.size();
    }
};



/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];
        });

        int length = envelopes.size();
        vector<int> dp(length,1);
        int ret=1;

        for(int i=1;i<length;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(envelopes[j][0]<envelopes[i][0]&&envelopes[j][1]<envelopes[i][1])
                    dp[i]=max(dp[i],dp[j]+1);
                ret=max(ret,dp[i]);
            }
        }
        return ret;
    }
}; 
 */