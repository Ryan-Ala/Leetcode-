class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        unordered_map<char,char> Hash;
        unordered_set<char> used;
        for(int i=0;i<m;i++)
        { 
            if(!Hash.count(s[i]))  // 模式床s[i]没有被映射过
            {
                if(used.count(t[i]))  // 必须要两个字符都没有被映射如果T已经被映射过了那么就说明有错误返回0
                return 0;
                // 如果两个都没有被映射过，那么将对应的字符进行映射
                Hash[s[i]]=t[i];  // 映射
                used.insert(t[i]); // 记录 比较串 中的 t[i]已经被映射过
            }
            else
            {
                if(Hash[s[i]]!=t[i])  //如果模式串S[i]已经映射过了那么比较是否等于之前映射的值如果不相等则不匹配
                return 0;
            }
        }
        return 1;
    }
};