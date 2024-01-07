class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int ret = 0, res = 1;
        for (int k = 0; k < j - i + 1; k++)
        {
            ret += res;
            res *= 2;
        }
        ret <<= i;
        ret = ~ret;
        M <<= i;
        N &= ret;
        N |= M;
        return N;
    }
};