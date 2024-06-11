class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visit,Hash(wordList.begin(),wordList.end());
        if(beginWord==endWord)return 0;
        if(!Hash.count(endWord)) return 0;

        queue<string> q;
        int ret=0;
        q.push(beginWord);
        while(q.size())
        {
            ret++;
            int sz=q.size();
            while(sz--)
            {
                string temp = q.front();
                q.pop();
                for(int i=0;i<temp.size();i++)
                {
                    string cnt = temp;
                    for(int j=0;j<32;j++)
                    {
                        cnt[i]='a'+j;
                        if(Hash.count(cnt)&&!visit.count(cnt))
                        {
                            if(cnt==endWord) return ret+1;
                            visit.insert(cnt);
                            q.push(cnt);
                        }
                    }
                }
            }
        }
        return 0;
    }
};