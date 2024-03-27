class Solution {
public:
    unordered_map<long long,int> Hash;
    int dfs(long long n)
    {
        if(n<=3) return n-1;
        if(Hash[n]) return Hash[n];

        if(n%2==0)
        {
            Hash[n]=dfs(n/2)+1;
        }
        else
        {
            if(n&2)
            Hash[n]=dfs(n+1)+1;
            else
            Hash[n]=dfs(n-1)+1;
        }
        return Hash[n];   
    }
    int integerReplacement(int n) {
        return dfs(n);
    }
};