#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

class com
{
public:
    bool operator()(pair<string, int>& a, pair<string, int>& b)
    {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};

int main() {
    string str;
    while (getline(cin, str)) { // 注意 while 处理多个 case
        map<string, int> Hash;
        int n = str.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (str[i] == ' ' || str[i] == '.')
            {
                string ret = str.substr(j, i - j);
                if (isupper(ret[0]))
                    ret[0] = tolower(ret[0]);
                Hash[ret]++;
                j = i + 1;
            }
        }
        vector<pair<string, int>> ret(Hash.begin(), Hash.end());
        sort(ret.begin(), ret.end(), com());
        for (auto& e : ret)
            cout << e.first << ":" << e.second << endl;
    }
}
// 64 位输出请用 printf("%lld")