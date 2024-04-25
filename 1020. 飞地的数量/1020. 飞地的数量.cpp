class Solution {
public:
    int m,n;
    int x[4]={1,-1,0,0},y[4]={0,0,1,-1};
    bool Hash[301][301];
public:
    bool flag=0;
    int count=0;
    void dfs(vector<vector<int>>& grid,int ii,int jj)
    {
        count++;
        Hash[ii][jj]=1;
        for(int k=0;k<4;k++)
        {
            int i=ii+x[k];
            int j=jj+y[k];
            if(i>=0&&i<m&&j>=0&&j<n&&!Hash[i][j]&&grid[i][j]==1)
            {
                if(i==0 || j==0 || i==m-1||j==n-1 )
                {
                    flag=1;
                }
                dfs(grid,i,j);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        m=grid.size();
        n=grid[0].size();
        int tt=0;
        for(int i=1;i<m-1;i++)
        for(int j=1;j<n-1;j++)
        {
            if(grid[i][j]==1&&!Hash[i][j])
            {
                flag=0;
                count=0;
                dfs(grid,i,j);
                if(!flag)
                tt+=count;
            }
        }
        return tt;
    }
};