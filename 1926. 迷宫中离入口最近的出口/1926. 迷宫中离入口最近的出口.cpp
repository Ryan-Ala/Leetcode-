class Solution {
public:
    int x[4]={1,-1,0,0},y[4]={0,0,1,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<bool>> Hash(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int step =0;
        while(q.size())
        {
            step++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto [a,b] = q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int xx=x[k]+a,yy=y[k]+b;
                    if(xx>=0&&yy>=0&&xx<m&&yy<n&&maze[xx][yy]=='.'&&Hash[xx][yy]==0)
                    {
                        if(xx==0||yy==0||xx==m-1||yy==n-1)
                        return step;
                        Hash[xx][yy]=1;
                        q.push({xx,yy});
                    }
                }
            }
        }
        return -1;
    }
};