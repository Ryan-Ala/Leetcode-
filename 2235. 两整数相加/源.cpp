class Solution {
public:
    int sum(int num1, int num2) {
        int x;
        unsigned int y;
        while (num2 != 0)
        {
            x = num1 ^ num2;  //�޽�λ���
            y = (num1 & num2) << 1;  //�����λ�� a&b ���Եó���Щ��Ҫ��λ
            num1 = x;
            num2 = y;
        }
        return num1;
    }
};