#include<iostream>
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
int main()
{
    int n;
    std::cout << "Please input n" << std::endl;
    std::cin >> n;
    Solution st;
    std::cout << st.climbStairs(n);
}