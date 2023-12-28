class Solution {
public:
    int captureForts(vector<int>& forts) {
        if (forts.size() < 3)
            return 0;
        int left = 0, right = 1, max = 0, length = forts.size();


        while (right < length)
        {
            while (left < length && forts[left] != 0)
                left++;
            right = left + 1;
            while (right < length && forts[right] == 0)
                right++;
            if (left > 0 && right < length && forts[left - 1] + forts[right] == 0)
            {
                if (max < right - left)
                    max = right - left;
            }
            left = right++;
        }
        return max;
    }
};