class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ret;
        for(auto &e:nums)
        {
            ret.push_back(to_string(e));
        }
        sort(ret.begin(),ret.end(),[&](string &a,string &b){
            return a+b>b+a;   //按照字符串组合的大小进行排序
        });

        string ans;
        for(auto& e:ret)  //最后拼接即可
        ans+=e;
        if(ans[0]=='0')return "0";
        return ans;
    }
};