class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int count = 0, max_count = 0;
        for (auto& e : seats)
        {
            if (e == 0)
                count++;
            else
                count = 0;
            if (max_count < count)
                max_count = count;
        }
        int max = 0, max1 = 0;
        for (auto& e : seats)
        {
            if (e == 0)
                max++;
            else
                break;
        }
        for (auto e = seats.rbegin(); e != seats.rend(); e++)
        {
            if (*e == 0)
                max1++;
            else
                break;
        }
        max = fmax(max, max1);
        return (max_count - 1) / 2 + 1 > max ? (max_count - 1) / 2 + 1 : max;
    }
};