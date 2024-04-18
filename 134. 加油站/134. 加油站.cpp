class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> ret(gas.size());
        for(int i=0;i<gas.size();i++)
        {
            ret[i]=gas[i]-cost[i];
            //cout<<ret[i]<<" ";
        }
        for(int i=0;i<gas.size();i++)
        {
            if(ret[i]>=0)
            {
                int sum=0;
                for(int j=i;j<gas.size();j++)
                {
                    sum+=ret[j];
                    if(sum<0)
                    {
                        if(j>i)
                        {
                            i=j;
                            break;
                        }
                        else
                        return -1;
                        
                    }
                    
                    
                }
                if(sum>=0)
                {
                    for(int j=0;j<i;j++)
                    {
                        sum+=ret[j];
                        if(sum<0)
                        {
                             if(j>i)
                            {
                                i=j;
                                break;
                            }
                            else
                                return -1;
                        }
                    }
                }
               
                if(sum>=0)
                return i;

            }
        }
        return -1;
    }
};