class Solution {
public:
    int minimumPossibleSum(int n,int target) {
        if(n==1)return 1;

        long long left_max = 0;
        if(target/2>=n)
        return ((1+n)*n/2ll)%1000000007;

        left_max = ((1+(target/2ll)%1000000007)*(target/2ll)/2)%1000000007;
        n -= target/2;
        left_max+=((target+(target+n-1ll)%1000000007)*(n)/2ll)%1000000007;
        return left_max%1000000007; 
    }
};