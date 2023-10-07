class Solution {
    int color, ret;
    int m, n;
    int x[4] = { 0,0,1,-1 }, y[4] = { 1,-1,0,0 };
public:
    void dfs(vector<vector<int>>& image, int sr, int sc)
    {
        image[sr][sc] = color;
        for (int k = 0; k < 4; k++)
        {
            int i = sr + x[k];
            int j = sc + y[k];
            if (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == ret)
                dfs(image, i, j);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        m = image.size();
        n = image[0].size();
        this->color = color;
        this->ret = image[sr][sc];  //记录是什么颜色需要被修改
        dfs(image, sr, sc);
        return image;
    }
};