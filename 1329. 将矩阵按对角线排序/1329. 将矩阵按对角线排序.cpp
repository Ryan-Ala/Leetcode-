class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        unordered_map<int,vector<int>> Hash;
        unordered_map<int,int> res;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                Hash[j-i].push_back(mat[i][j]);
        for(auto &[a,vec]:Hash)
            sort(vec.begin(),vec.end());
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
               mat[i][j] = Hash[j-i][res[j-i]++];
        return mat;
    }
};