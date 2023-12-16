class Solution {
public:
    string minWindow(string s, string t) {
        int Hash_1[128] = { 0 };
        int Hash_2[128] = { 0 };
        int size = 0;
        for (auto& e : t)
            if (Hash_1[e]++ == 0)
                size++;
        char ch;
        int left = 0, right = 0, count = 0, length = s.length(), min = INT_MAX, begin = -1;
        while (right < length)
        {
            ch = s[right++];
            if (++Hash_2[ch] == Hash_1[ch])
                count++;

            while (count == size)
            {
                if (min > right - left)
                {
                    min = right - left;
                    begin = left;
                }
                ch = s[left++];
                if (Hash_2[ch]-- == Hash_1[ch])
                    count--;
            }
        }
        if (begin == -1)
            return "";
        return s.substr(begin, min);
    }
};