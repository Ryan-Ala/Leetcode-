class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist = vector<vector<int>>(m,vector<int>(n,-1));
        int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(q.size())
        {
            auto [a,b] = q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x= a+xx[k],y=b+yy[k];
                if(x>=0&&y>=0&&x<m&&y<n&&dist[x][y]==-1)
                {
                    dist[x][y]=dist[a][b]+1;
                    q.push({x,y});
                }
            }
        }
        return dist;
    }
};