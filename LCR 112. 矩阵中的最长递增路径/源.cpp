class Solution {
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
    int m, n;
    int mem[201][201];
public:
    int dfs(vector<vector<int>>& matrix, int ii, int jj)
    {
        if (mem[ii][jj])
            return mem[ii][jj];

        int ret = 1;
        for (int k = 0; k < 4; k++)
        {
            int i = ii + x[k];
            int j = jj + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && matrix[ii][jj] < matrix[i][j])
                ret = max(dfs(matrix, i, j) + 1, ret);  //+1要写在dfs后面，如果写在max函数外面，当一个树上下左右一旦能够进行遍历，每次符合条件的遍历就会使ret递增一次，导致ret偏大，就如示例一在九宫格中间时，遍历4和6时ret变成3，再到中间下面时，两次遍历时ret又自增两次
        }
        mem[ii][jj] = ret;

        return ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        m = matrix.size();
        n = matrix[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, dfs(matrix, i, j));
            }
        return ret;
    }
};