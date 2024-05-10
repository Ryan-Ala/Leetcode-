class Solution {
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int ans;
    int m,n;
public:
    void dfs(vector<vector<int>>& grid,int x,int y)
    {
        grid[x][y]=2;

        for(int k=0;k<4;k++)
        {
            int i=x+dx[k],j=y+dy[k];
            if(i>=0&&i<m&&j>=0&&j<n)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                }
                else if(grid[i][j]==0)
                ans++;  // 如果旁边是海洋，周长++
            }
            else  
            {   // 如果到达地图边界,周长++
                ans++;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]==1)
        dfs(grid,i,j);

        return ans;
    }
};