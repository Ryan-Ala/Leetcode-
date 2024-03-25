class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size(),n=mat[0].size(),i=0,j=0;
        int num=m*n;
        while(ans.size()!=num)
        {
            while(i!=-1&&j!=n)  //上
                ans.push_back(mat[i--][j++]);
            if(i==-1&&j!=n)
            i++;
            else
            {i+=2;j--;}
            while(j!=-1&&i!=m)
                ans.push_back(mat[i++][j--]);
            if(j==-1&&i!=m)
            j++;
            else
            {i--;j+=2;}
        }
        return ans;
    }
};