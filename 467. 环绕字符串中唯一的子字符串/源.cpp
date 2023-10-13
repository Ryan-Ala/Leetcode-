class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);  //dp�����¼�Ե�ǰ�ַ���β�ķ����������ִ�
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] += dp[i - 1];   //dp[i]�Լ�Ϊ1������ǰ�ĵ����ַ������ټ����Ե�ǰ�ַ���β���ִ���Ŀ
        }
        int Hash[26] = { 0 };
        for (int i = 0; i < n; i++)
        {
            Hash[s[i] - 'a'] = max(Hash[s[i] - 'a'], dp[i]);  //��¼���ֵ��ȥ�أ���ֹ1ͳ���ظ��ִ�
        }
        int sum = 0;
        for (auto& e : Hash)
            sum += e;
        return sum;
    }
};