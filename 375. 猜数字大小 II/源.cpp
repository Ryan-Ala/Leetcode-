class Solution {
    int mem[201][201];
public:
    int dfs(int left, int right)
    {
        //�������1:��left��rightͬΪ1ʱ����һ����ݹ��ʹ������С�������䣬��ʱ�𰸷���0
        //�������2:��left��right���ʱ��˵������Ҷ�ӽڵ㣬��ʱ�϶�Ϊ��ȷ�𰸣�����֧��������0
        if (left >= right)
            return 0;

        if (mem[left][right])   //���仯����
            return mem[left][right];

        int ret = INT_MAX;
        for (int head = left; head < right; head++)
        {
            int x = dfs(left, head - 1);  //���ֵ
            int y = dfs(head + 1, right); //�Ҳ�ֵ

            //Ѱ����С�Ľ�Ǯ
            ret = min(ret, head + max(x, y));//����ѡ���ȷ���ܹ����㹻��Ǯ)
        }

        mem[left][right] = ret;

        return ret;
    }
    int getMoneyAmount(int n) {
        return dfs(1, n);
    }
};

