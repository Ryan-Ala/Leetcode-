class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26)
            return 0;
        int x = 0, ret;
        for (auto e : astr)
        {
            ret = e - 'a';
            if (x >> ret & 1)  //使用位运算来检查当前位置对应的字母是否存在，如果存在，则说明有重复
                return 0;
            else
                x = 1 << ret | x;  //如果不存在，就将改二进制位改为1
        }
        return 1;
    }
};