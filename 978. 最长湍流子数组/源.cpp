class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max_num = 1;
        int length = arr.size();
        vector<int> f(length);  //最后呈现上升趋势
        auto g = f;  //最后呈现下降趋势
        f[0] = g[0] = 1;
        for (int i = 1; i < length; i++)
        {
            f[i] = arr[i] > arr[i - 1] ? g[i - 1] + 1 : 1;  //最后呈现上升则g[i-1]+1,否则自己成为一个数组，长度为1
            g[i] = arr[i] < arr[i - 1] ? f[i - 1] + 1 : 1;
            max_num = max(max_num, max(f[i], g[i]));
        }
        return max_num;
    }
};