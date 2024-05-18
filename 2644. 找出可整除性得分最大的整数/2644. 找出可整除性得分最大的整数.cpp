class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        unordered_map<int,int>Hash;
        unordered_set<int> Hash_1;
        for(auto e:nums)
        {
            Hash[e]++;
        }

        for(auto e:divisors)
        {
            Hash_1.insert(e);
        }

        int count=0,ans=INT_MAX;
        for(auto a1:Hash_1)
        {
            int tmp = 0;
            for(auto& [b1,b2]:Hash)
            {
                if(b1%a1==0)
                {
                    tmp+=b2;
                }
            }
            if(count<tmp)
            {
                count=tmp;
                ans=a1;
            }
            else if(count==tmp)
            {
                ans=min(ans,a1);
            }
        }
        return ans;

    }
};