class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        unordered_set<int> Hash;
        int max=0,min=INT_MAX;
        for(auto &e:places)
        {
            
            max=fmax(max,e);
            if(e!=0)
            {
                min=fmin(min,e);
                if(Hash.count(e))
                {
                    return 0;
                }
            }
            Hash.insert(e);
        }
        if(max-min<=4)
        return 1;
        
        return 0;
    }
};