class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        while(k&&cnt<nums.size())
        {
            if(nums[cnt]<0)
            {
                nums[cnt]=nums[cnt]*-1;
                cnt++;
            }
            else
                break;
            k--;
        }
        int sum=0;
        if(k==0)
        {
            for(auto &e:nums)
            sum+=e;
            return sum;
        }
        int a=0;
         cout<<a<<" "<<cnt;
        if(cnt==nums.size())
        {
            a=cnt-1;
        }
        else if(cnt!=0)
        {
            if(nums[cnt]<nums[cnt-1])
            a=cnt;
            else
            a=cnt-1;
        }
        
        if(k%2==1)
        {
            nums[a]*=-1;
        }
        //cout<<a;
        
        for(auto &e:nums)
        sum+=e;
        

        return sum;
    }
};