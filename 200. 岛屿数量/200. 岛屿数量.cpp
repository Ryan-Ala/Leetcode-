class Solution {
    int m,n;
    int x[4]={1,-1,0,0},y[4]={0,0,1,-1};
    bool Hash[301][301];
public:
    void dfs(vector<vector<char>>& grid,int ii,int jj)
    {
        Hash[ii][jj]=1;
        for(int k=0;k<4;k++)
        {
            int i=ii+x[k];
            int j=jj+y[k];
            if(i>=0&&i<m&&j>=0&&j<n&&!Hash[i][j]&&grid[i][j]=='1')
            dfs(grid,i,j);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(!Hash[i][j]&&grid[i][j]=='1')
            {
                count++;
                dfs(grid,i,j);
            }
        }
        return count;
    }
};