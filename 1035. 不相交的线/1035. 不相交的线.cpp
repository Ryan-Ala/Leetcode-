class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        //本题参考最长公共子序列,只要是最长公共子序列,连线就不会相交
        int m1=nums1.size(),m2=nums2.size();
        vector<vector<int>> dp(m1+1,vector<int>(m2+1));

        for(int i=1;i<=m1;i++)
        for(int j=1;j<=m2;j++)
        {
            if(nums1[i-1]==nums2[j-1]) //当，末尾字符相同时，最长公共子序列就从两个数字的前一个位置寻找
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else  //如果不相同,那么两个数组的末尾就不可能构成新的最长公共子序列,
            //此时就从[0,i][0,j-1]  [0,i-1][0,j]  [0,i-1][0,j-1] 选择最长的,由于[0,i-1][0,j]包含了[0,i-1][0,j-1],所以只需要比较两种即可
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
            }
        }
        return dp[m1][m2];
    }
};