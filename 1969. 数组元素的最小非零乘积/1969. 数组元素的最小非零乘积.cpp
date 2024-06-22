class Solution {
public:
    int minNonZeroProduct(int p) {
        const int mod = 1000000007;
        long long ans = ( (1ll<<p) -1 ) % mod,k = (1ll<<(p-1))-1;

        for(long long muti = ( ( 1ll<<p ) -2 ) % mod ; k ; k >>= 1 )
        {
            if(k&1)
            ans = ( ans*muti ) % mod;
            muti= ( muti*muti ) % mod;
        }
        return ans;
    }
};


