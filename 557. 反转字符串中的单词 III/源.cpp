class Solution {
public:
    string reverseWords(string s) {
        string ss, last;
        string::iterator ch = s.begin(), it;
        while (ch != s.end())
        {
            if (*ch == ' ')
            {
                it = ch;
                string sss(ss.rbegin(), ss.rend());
                last += sss + ' ';
                ss.clear();
            }
            else
                ss += *ch;
            ch++;
        }
        string aa(ss.rbegin(), ss.rend());
        last += aa;
        return last;
    }
};