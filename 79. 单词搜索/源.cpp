class Solution {
    bool Hash[7][7];
    int m, n, x[4] = { 0,1,-1,0 }, y[4] = { 1,0,0,-1 };
public:
    bool dfs(vector<vector<char>>& board, string& word, int ii, int jj, int pos)
    {
        if (pos == word.size())
        {
            return 1;
        }
        for (int k = 0; k < 4; k++)
        {
            int i = ii + x[k];
            int j = jj + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && word[pos] == board[i][j] && !Hash[i][j])
            {
                Hash[i][j] = 1;
                if (dfs(board, word, i, j, pos + 1))
                    return 1;
                Hash[i][j] = 0;
            }
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    Hash[i][j] = 1;
                    if (dfs(board, word, i, j, 1))
                        return 1;
                    Hash[i][j] = 0;
                }
            }
        return 0;
    }
};