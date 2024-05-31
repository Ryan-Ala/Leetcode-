class Solution {
public:
    bool checkPerfectNumber(int num) {
        int cnt = sqrt(num);
        int sum=0;
        while(cnt)
        {
            if(num%cnt==0)
            {
                
                sum+=cnt;
                if(cnt*cnt!=num&&cnt!=1)
                {
                    sum+=num/cnt;
                }
               
                if(sum>num)
                return 0;
            }
            cnt--;
        }
        return sum==num&&num!=1;
    }
};