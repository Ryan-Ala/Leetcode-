class Solution {
public:
    string decodeString(string s) {
        stack<string> str_s;
        stack<int> num_s;
        str_s.push("");
        int m = s.size();
        int i=0;
        while(i<m)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int num=0;
                while(s[i]>='0'&&s[i]<='9')
                {
                    num=num*10+(s[i++]-'0');
                }
                num_s.push(num);
            }
            else if(s[i]=='[')
            {
                i++;
                string ret;
                while(s[i]>='a'&&s[i]<='z')
                {
                    ret+=s[i++];
                }
                str_s.push(ret);
            }
            else if(s[i]==']')
            {
                i++;
                int k=num_s.top();
                num_s.pop();
                string ret = str_s.top();
                str_s.pop();

                while(k--)
                {
                    str_s.top()+=ret;
                }
            }
            else 
            {
                while(i<m&&s[i]>='a'&&s[i]<='z')
                {
                    str_s.top()+=s[i++];
                }
            }
        }
        return str_s.top();
    }
};