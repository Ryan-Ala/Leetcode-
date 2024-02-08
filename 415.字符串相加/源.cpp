#include<iostream>
class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.length() - 1, size2 = num2.length() - 1, num = 0;
        string s;
        while (size1 > -1 || size2 > -1 || num != 0)
        {
            num += ((size1 >= 0 ? num1[size1--] - '0' : 0) + (size2 >= 0 ? num2[size2--] - '0' : 0));
            s.push_back('0' + num % 10);
            num /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};