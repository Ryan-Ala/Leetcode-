class Solution {
public:
    int countDigitOne(int n) {
        int count = 0, num = n;
        long long i = 1;
        while (num)
        {
            if (num % 10 == 0)
            {
                count += (num / 10) * i;
            }
            else if (num % 10 == 1)
            {
                count += (num / 10) * i + (n % i) + 1;
            }
            else
            {
                count += ceil(num / 10.0) * i;
            }
            i *= 10;
            num /= 10;
        }
        return count;
    }
};