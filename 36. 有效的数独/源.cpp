class Solution {
    bool row[9][10], cur[9][10], Hash[3][3][10];
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (row[i][num] || cur[j][num] || Hash[i / 3][j / 3][num])
                        return 0;
                    row[i][num] = cur[j][num] = Hash[i / 3][j / 3][num] = 1;
                }

            }
        return 1;
    }
};