class Solution {
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
    int m, n;
public:
    void dfs(vector<vector<char>>& board, int sr, int sc)
    {
        board[sr][sc] = '.';
        for (int k = 0; k < 4; k++)
        {
            int i = sr + x[k], j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
                dfs(board, i, j);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '.')
                    board[i][j] = 'O';
            }
    }
};