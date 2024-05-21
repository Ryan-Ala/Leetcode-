class Solution {
    unordered_set<char> Hash;
public:
    Solution()
    {
        char ret[10]={'a','e','i','o','u','A','E','I','O','U'};
        for(auto& e:ret)
        Hash.insert(e);
    }
    bool halvesAreAlike(string s) {
        int left=0,right=0;
        int i=0,length=s.size()/2;
        for(;i<length;i++)
        {
            if(Hash.count(s[i]))
            left++;
        }
        for(;i<s.size();i++)
        {
            if(Hash.count(s[i]))
            right++;
        }
        //cout<<left<<" "<<right<<endl;
        if(left==right)
        return 1;
        return 0;
    }
};