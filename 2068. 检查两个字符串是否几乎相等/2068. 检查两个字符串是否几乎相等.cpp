class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<int,int> Hash1,Hash2;
        
        for(auto e:word1)
        Hash1[e]++;
        for(auto e:word2)
        Hash2[e]++;

        for(auto [a,b]:Hash1)
        {
            if(abs(b-Hash2[a])>3)
            return 0;
        }

        for(auto [a,b]:Hash2)
        {
            if(abs(b-Hash1[a])>3)
            return 0;
        }


        return 1;
    }
};