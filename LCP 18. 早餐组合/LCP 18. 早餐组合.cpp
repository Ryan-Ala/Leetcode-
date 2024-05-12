class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        long long sum=0;
        sort(drinks.begin(),drinks.end());

        for(auto e:staple)
        {
            if(e<=x)
            {
                //  寻找第一个 > start 的元素的下标
                auto tmp = upper_bound(drinks.begin(),drinks.end(),x-e);
                if(tmp == drinks.end())
                {
                    sum+=drinks.size();
                }
                //else if  tmp==drinks.begin()
                else if(tmp!=drinks.begin())
                {
                    sum+=(tmp-drinks.begin());
                    // cout<<tmp-drinks.begin()<<"  ";
                }
                
                sum%=1000000007;
            }
        }
        return sum;

    }
};