class Solution {
    bool Hash[16];
    int sum = 0, n;
public:
    void dfs(int pos)
    {
        if (pos == n + 1)
        {
            sum++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!Hash[i] && (i % pos == 0 || pos % i == 0))
            {
                Hash[i] = 1;
                dfs(pos + 1);
                Hash[i] = 0;
            }
        }
    }
    int countArrangement(int n) {

        this->n = n;
        dfs(1);
        return sum;

    }
};
