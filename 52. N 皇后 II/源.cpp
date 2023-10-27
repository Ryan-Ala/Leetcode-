class Solution {
    int n, check_1[20], check_2[20], check[20], count = 0;
public:
    void dfs(int pos)
    {
        if (pos == n)
        {
            count++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!check[i] && !check_1[pos - i + n] && !check_2[pos + i])
            {
                check[i] = check_1[pos - i + n] = check_2[pos + i] = 1;
                dfs(pos + 1);  //ÏÂÒ»²ã
                check[i] = check_1[pos - i + n] = check_2[pos + i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        this->n = n;
        dfs(0);
        return count;
    }
};