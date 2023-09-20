class Solution {
    vector<string> ans;
    string ret;
    int left = 0, right = 0, size;
public:
    void dfs()
    {
        if (right == size)  //ret.length()==2*size
            ans.push_back(ret);

        if (left < size)
        {
            left++;
            ret.push_back('(');
            dfs();
            ret.pop_back();
            left--;
        }
        if (right < left)
        {
            right++;
            ret.push_back(')');
            dfs();
            ret.pop_back();
            right--;
        }
    }
    vector<string> generateParenthesis(int n) {
        size = n;
        dfs();
        return ans;
    }
};