class Solution {
public:
    typedef pair<long long,int> pa;
    long long kSum(vector<int>& nums, int k) {
        long long max_num=0;
        for(auto &e:nums)
        {
            if(e>0)
            max_num+=e;
            else
            e*=-1;
        }
        if(k==1)return max_num;
        sort(nums.begin(),nums.end());
        priority_queue<pa,vector<pa>,greater<pa>> q;
        q.push({nums[0],0});

        for(int pos=0;pos<k-1;pos++)
        {
            auto [sum,i] = q.top();
            q.pop();

            if(pos==k-2) return max_num-sum;
            if(i+1<nums.size())
            {    //类似于递归(广度递归加 控制大小)
                q.push({sum-nums[i]+nums[i+1],i+1});
                q.push({sum+nums[i+1],i+1});
            }
        }
        return -1;
    }
};