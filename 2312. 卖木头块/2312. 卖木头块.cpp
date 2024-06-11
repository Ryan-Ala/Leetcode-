class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> pri(m+1,vector<int>(n+1));
        for(auto &e:prices)
        {
            pri[e[0]][e[1]]=e[2];   //存储每一个大小下对应的价格,便于后续遍历
        }

        vector<vector<long long>> f(m+1,vector<long long>(n+1));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=pri[i][j];
                //枚举每一个切割的方案
                for(int k=1;k<i;k++)
                f[i][j]=max(f[i][j],f[k][j]+f[i-k][j]);

                for(int k=1;k<j;k++)
                f[i][j]=max(f[i][j],f[i][k]+f[i][j-k]);
            }
        }
        return f[m][n];
    }
};