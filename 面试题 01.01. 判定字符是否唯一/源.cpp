class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26)
            return 0;
        int x = 0, ret;
        for (auto e : astr)
        {
            ret = e - 'a';
            if (x >> ret & 1)  //ʹ��λ��������鵱ǰλ�ö�Ӧ����ĸ�Ƿ���ڣ�������ڣ���˵�����ظ�
                return 0;
            else
                x = 1 << ret | x;  //��������ڣ��ͽ��Ķ�����λ��Ϊ1
        }
        return 1;
    }
};