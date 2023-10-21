class Solution {
    bool row[9][10], cur[9][10], Hash[3][3][10];
public:
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if (i == 8 && j == 9)
            return 1;
        if (j == 9)
        {
            i += 1;
            j = 0;
        }
        if (board[i][j] == '.')
        {
            for (int res = 1; res <= 9; res++)
            {
                if (!row[i][res] && !cur[j][res] && !Hash[i / 3][j / 3][res])
                {
                    board[i][j] = res + '0';
                    row[i][res] = cur[j][res] = Hash[i / 3][j / 3][res] = 1;
                    if (dfs(board, i, j + 1))
                        return 1;
                    else
                    {
                        board[i][j] = '.';
                        row[i][res] = cur[j][res] = Hash[i / 3][j / 3][res] = 0;
                    }
                }
            }
        }
        else
            if (dfs(board, i, j + 1))
                return 1;
        return 0;

    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int res = board[i][j] - '0';
                    row[i][res] = cur[j][res] = Hash[i / 3][j / 3][res] = 1;
                }
            }
        dfs(board, 0, 0);
    }
};