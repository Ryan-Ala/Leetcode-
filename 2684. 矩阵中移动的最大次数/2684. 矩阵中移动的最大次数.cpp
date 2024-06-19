class Solution {
public:
    int count;
    int m,n;
    bool mem[1005][1005];  //起到一个 标记的作用
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(mem[i][j])
        {
            return;
        }
        count=max(count,j);
        mem[i][j]=1;
        if(j==n-1)
        return;
        for(int k=-1;k<=1;k++)
        {
            
            if(i+k>=0&&i+k<m&&grid[i][j]<grid[i+k][j+1])
            {
                dfs(i+k,j+1,grid);
            }
        }
    }
    int maxMoves(vector<vector<int>>& grid) {
        int row =0;
        m=grid.size(),n=grid[0].size();
        
        for(int j=0;j<m;j++)
        dfs(j,0,grid);

        return count;
        
    }
};