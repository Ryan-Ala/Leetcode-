class Solution {
public:
    int sum(int num1, int num2) {
        int x;
        unsigned int y;
        while (num2 != 0)
        {
            x = num1 ^ num2;  //无进位相加
            y = (num1 & num2) << 1;  //处理进位， a&b 可以得出哪些需要进位
            num1 = x;
            num2 = y;
        }
        return num1;
    }
};