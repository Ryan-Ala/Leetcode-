class Solution {
    int x[8] = { 0,0,1,-1,-1,1,1,-1 }, y[8] = { 1,-1,0,0,-1,1,-1,1 };
    int m, n;
public:
    void dfs(vector<vector<char>>& board, int sr, int sc)
    {
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
            int i = sr + x[k], j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'M')
                count++;
        }
        if (count)
        {
            board[sr][sc] = count + '0';
            return;
        }
        else
        {
            board[sr][sc] = 'B';
            for (int k = 0; k < 8; k++)
            {
                int i = sr + x[k], j = sc + y[k];
                if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'E')
                    dfs(board, i, j);
            }
        }

    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int x = click[0], y = click[1];

        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        dfs(board, x, y);
        return board;
    }
};