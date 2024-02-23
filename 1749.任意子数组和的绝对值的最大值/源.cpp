#include<iostream>

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int count_max = 0, count_min = 0, max = 0, min = 0;
        for (auto num : nums)
        {
            count_min += num;
            count_max += num;
            if (count_max < 0)
                count_max = 0;
            if (count_min > 0)
                count_min = 0;
            if (max < count_max)
                max = count_max;
            if (min > count_min)
                min = count_min;

        }
        return fmax(max, -min);
    }
};