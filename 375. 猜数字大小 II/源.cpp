class Solution {
    int mem[201][201];
public:
    int dfs(int left, int right)
    {
        //特殊情况1:当left和right同为1时，下一层左递归会使右区间小于左区间，此时答案返回0
        //特殊情况2:当left和right相等时，说明到了叶子节点，此时肯定为正确答案，无需支付，返回0
        if (left >= right)
            return 0;

        if (mem[left][right])   //记忆化搜索
            return mem[left][right];

        int ret = INT_MAX;
        for (int head = left; head < right; head++)
        {
            int x = dfs(left, head - 1);  //左侧值
            int y = dfs(head + 1, right); //右侧值

            //寻找最小的金钱
            ret = min(ret, head + max(x, y));//左右选大的确保能够有足够的钱)
        }

        mem[left][right] = ret;

        return ret;
    }
    int getMoneyAmount(int n) {
        return dfs(1, n);
    }
};

