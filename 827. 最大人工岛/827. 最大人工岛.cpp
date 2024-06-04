class Solution {
public:
    int xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
    vector<vector<int>> Hash;
    vector<int> ret;
    int m,n;
    int count=0;
    int tmp=1;
    int sum = 0;
    int sum_max=0;
    bool flag=0;
    queue<pair<int,int>> q,p;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        Hash[i][j]=tmp;
        count++;
        for(int k=0;k<4;k++)
        {
            int x=xx[k]+i,y=yy[k]+j;
            if(x>=0&&x<m&&y>=0&&y<n)
            {
                if(grid[x][y]==1)
                {
                    if(!Hash[x][y])
                        dfs(grid,x,y);
                }
                else
                {
                    q.push({x,y});
                    p.push({i,j});
                }
            }
        }
    }
    void find_max()
    {
        while(q.size())
        {
            auto [i,j] = q.front();
            q.pop();
            auto [ii,jj] = p.front();
            p.pop();
            int sh = Hash[ii][jj], cnt = ret[sh],temp=0;
            unordered_map<int,int> map;
            map[sh]++;
            for(int k=0;k<4;k++)
            {
                int x=xx[k]+i,y=yy[k]+j;
                if(x>=0&&x<m&&y>=0&&y<n)
                {
                    int ha=Hash[x][y];  //可连接的
                    if(ha)
                    {
                        if(!map.count(ha))
                        {
                            map[ha]++;
                            temp+=ret[ha];
                        }
                    }
                }
                
            }
            if(map.size())
            {
                sum=max(sum,temp+cnt+1);
            }
            else
                sum=max(sum,cnt+1);
        }
        if(sum==0)
        sum=sum_max;
        if(!flag)
        sum=1;
    }
    void fun(vector<vector<int>>& grid)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!Hash[i][j])
                {
                    flag=1;
                    count=0;
                    dfs(grid,i,j);
                    ret.push_back(count);
                    sum_max = max(sum_max,count);
                    tmp++;
                }
                
            }
        }
        find_max();
    }

    int largestIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        Hash = vector(m,vector<int>(n,0));
        ret.push_back(0);
        fun(grid);
        return sum;
    }
};
