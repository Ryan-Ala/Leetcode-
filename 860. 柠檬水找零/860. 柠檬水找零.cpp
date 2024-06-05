class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //不需要管20美元，因为20美元不能找零
        int ten=0,five=0;
        for(auto& e:bills)
        {
            if(e==5) five++;
            else if(e==10)
            {
                if(five)
                {
                    five--;
                    ten++;
                }
                else
                return 0;
            }
            else
            {
                if(ten&&five)
                {
                    five--;
                    ten--;
                }
                else if(five>2)
                {
                    five-=3;
                }
                else
                return 0;
            }
        }
        return 1;
    }
};