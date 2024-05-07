class Solution {
public:
    int brokenCalc(int startValue, int target) {  //反推
        int count=0,a=startValue;
         
        while(target>startValue)
        {
            count++;
             if(target%2==0)
             {
                 target/=2;
             }
             else  //如果是奇数，那么一定是-1而来的，这里还原步骤即可
             target+=1;
        }
        return count+a-target;
    }
};