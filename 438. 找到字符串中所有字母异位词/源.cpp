/* class Solution {
private:
    unordered_map<char,int> ret1;
    unordered_map<char,int> ret2;

public:

    vector<int> findAnagrams(string s, string p) {
        for(char ch='a';ch<='z';ch++)
        {
            ret1[ch]=0;
            ret2[ch]=0;
        }
        vector<int> ans;
        if(p.length()>s.length())
        return ans;
        for(auto &e:p)
            ret1[e]++;

        int i=0,length=p.length();
        while(i<p.length())
            ret2[s[i++]]++;

        char ch;
        while(i<s.length())
        {
            if(ret1==ret2)
            ans.push_back(i-length);
            ret2[s[i-length]]--;
            ret2[s[i++]]++;
        }
        if(ret1==ret2)
           ans.push_back(i-length);
        return ans;

    }
}; */

class Solution {
private:
    int ret1[26] = { 0 };
    int ret2[26] = { 0 };
    bool cmp()
    {
        for (int i = 0; i < 26; i++)
        {
            if (ret1[i] != ret2[i])
                return 0;
        }
        return 1;
    }
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.length() > s.length())
            return ans;
        for (auto& e : p)
            ret1[e - 'a']++;

        int i = 0, length = p.length();
        while (i < p.length())
            ret2[s[i++] - 'a']++;

        char ch;
        while (i < s.length())
        {
            if (cmp())
                ans.push_back(i - length);
            ret2[s[i - length] - 'a']--;
            ret2[s[i++] - 'a']++;
        }
        if (cmp())
            ans.push_back(i - length);
        return ans;

    }
};

class Solution {
    int ret1[26] = { 0 };
    int ret2[26] = { 0 };
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.length() > s.length())
            return ans;
        for (auto& e : p)
            ret1[e - 'a']++;
        int count = 0;
        int i = 0, length = p.length();
        while (i < p.length())
        {
            if (++ret2[s[i] - 'a'] <= ret1[s[i] - 'a'])
                count++;
            i++;
        }
        while (i < s.length())
        {
            if (length == count)
                ans.push_back(i - length);
            if (ret2[s[i - length] - 'a']-- <= ret1[s[i - length] - 'a'])
                count--;
            if (++ret2[s[i] - 'a'] <= ret1[s[i] - 'a'])
                count++;
            i++;
        }
        if (length == count)
            ans.push_back(i - length);
        return ans;

    }
};