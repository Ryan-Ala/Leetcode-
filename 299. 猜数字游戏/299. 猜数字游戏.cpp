class Solution {
public:
    string getHint(string secret, string guess) {
        int m = secret.size();
        int count=0;
        unordered_map<char,int>gu,se;
        for(int i = 0;i<m;i++)
        {
            
            if(secret[i]==guess[i])
            count++;
            else
            {
                se[secret[i]]++;
                gu[guess[i]]++;
            }
                
        }
        int cnt  = 0;
        for(auto [e,num]:gu)
        {
            if(se.count(e))
            cnt+=min(num,se[e]);
        }
        string ans;
        ans+=to_string(count);
        ans+='A';
        ans+=to_string(cnt);
        ans+='B';
        return ans;
    }
};