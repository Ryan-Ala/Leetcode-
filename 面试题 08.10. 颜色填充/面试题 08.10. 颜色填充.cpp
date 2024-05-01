class Solution {
public:
    int newcolor,m,n,oldcolor;
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    vector<vector<bool>>Hash;
    void dfs(vector<vector<int>>& image,int sr,int sc)
    {
        image[sr][sc]=newcolor;
        Hash[sr][sc]=1;
        for(int k = 0;k<4;k++)
        {
            int x=sr+dx[k],y=sc+dy[k];
            if(x>=0&&y>=0&&x<m&&y<n&&image[x][y]==oldcolor&&!Hash[x][y])
            {
                dfs(image,x,y);
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        newcolor=newColor;
        m =image.size(),n=image[0].size();
        oldcolor=image[sr][sc];
        Hash = vector<vector<bool>> (m,vector<bool>(n));
        dfs(image,sr,sc);
        return image;
    }
};