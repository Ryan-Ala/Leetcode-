class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length() || s == t)
            return 0;
        int Hash_1[26] = { 0 }, Hash_2[26] = { 0 };
        for (auto& e : s)
            Hash_1[e - 'a']++;

        for (auto& e : t)
            Hash_1[e - 'a']--;

        for (int i = 0; i < 26; i++)
            if (Hash_1[i] != 0)
                return 0;
        return 1;
    }
};