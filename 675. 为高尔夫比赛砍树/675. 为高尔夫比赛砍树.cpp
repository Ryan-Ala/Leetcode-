class Solution {
public:
    int m,n;
    int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
    int Hash[51][51];
    int dfs(vector<vector<int>>& forest,int begin_x,int begin_y,int end_x,int end_y)
    {
        if(begin_x==end_x&&begin_y==end_y) return 0;

        queue<pair<int,int>> q;
        q.push({begin_x,begin_y});
        memset(Hash,0,sizeof Hash);
        Hash[begin_x][begin_y]=1;
        

        int ret = 0;
        while(q.size())
        {
            ret++;
            int sz = q.size();
            while(sz--)
            {
                auto [a,b] = q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x = a+xx[k],y=b+yy[k];
                    if(x>=0&&x<m&&y>=0&&y<n&&forest[x][y]!=0&&!Hash[x][y])
                    {
                        if(x==end_x&&y==end_y)
                        return ret;
                        q.push({x,y});
                        Hash[x][y]=1;
                    }
                }
            }

        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(),n=forest[0].size();
        //Hash = vector<vector<bool>>(m,vector<bool>(n));
        vector<pair<int,int>> ret;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(forest[i][j]>1)
                {
                    ret.push_back({i,j});
                }

            }
        }

        sort(ret.begin(),ret.end(),[&](pair<int,int>& a,pair<int,int>& b){
            return forest[a.first][a.second]<forest[b.first][b.second];
        });

        int sum = 0;
        int bx=0,by=0;
        for(auto [a,b]:ret)
        {
            int num = dfs(forest,bx,by,a,b);
            if(num==-1)return -1;
            sum+=num;
            bx=a;
            by=b;
        }
        return sum;
    }
};