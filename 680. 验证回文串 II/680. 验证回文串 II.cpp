class Solution {
public:
    bool dfs2(string &s,int left,int right)
    {
        if(left<0||right>=s.size())return 0;
        while(left<right&&s[left]==s[right])
        {
            left++;
            right--;
        }
        if(left>=right)
        return 1;
        return 0;
    }
    bool dfs(string &s,int left,int right)
    {
        while(left<right&&s[left]==s[right])
        {
            left++;
            right--;
        }
        if(left>=right)
        return 1;
        return dfs2(s,left+1,right)||dfs2(s,left,right-1)||dfs2(s,left-1,right)||dfs2(s,left,right+1);
    }
    bool validPalindrome(string s) {
        return dfs(s,0,s.size()-1);
    }
};