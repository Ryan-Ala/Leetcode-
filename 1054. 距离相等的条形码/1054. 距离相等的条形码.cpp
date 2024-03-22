class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int m = barcodes.size();
        int val,max_count=0;
        unordered_map<int,int> Hash;
        for(auto &e:barcodes)
        {
            if(++Hash[e]>max_count)
            {
                val =e;
                max_count=Hash[e];
            }
        }

        vector<int> ans(m);
        int pos=0;
        while(max_count--)
        {
            ans[pos]=val;
            pos+=2;
        }

        Hash.erase(val);
        for(auto [a,b]:Hash)
        {
            while(b--)
            {
                if(pos>=m)pos=1;
                ans[pos]=a;
                pos+=2;
            }
        }
        return ans;
    }
};