class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        vector<vector<int>> dist = vector<vector<int>>(m,vector<int>(n,-1));
        vector<vector<bool>> Hash = vector<vector<bool>>(m,vector<bool>(n));

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]==1)
        {
            Hash[i][j]==1;
            q.push({i,j});
            dist[i][j]=0;
        }

        while(q.size())
        {
            int sz=q.size();
            while(sz--)
            {
                auto [a,b] = q.front();
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int x=a+dx[k],y=b+dy[k];
                    if(x>=0&&y>=0&&x<m&&y<n&&dist[x][y]&&!Hash[x][y])
                    {
                        Hash[x][y]=1;
                        q.push({x,y});
                        dist[x][y]=dist[a][b]+1;
                    }
                }
            }
        }
        return dist;
    }
};