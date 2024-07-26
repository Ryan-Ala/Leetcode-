class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> Bank(bank.begin(),bank.end()),Hash;
        queue<string> q;
        q.push(startGene);
        int ret=0;
        string a="ACGT";
        if(startGene==endGene)return 0;
        if(!Bank.count(endGene))return -1;
        while(q.size())
        {
            ret++;
            int sz =q.size();  //不能直接用q.size(),这里需要区分每一层,直接用q.size()无法到达外层循环
            while(sz--)
            {
                string temp = q.front();
                q.pop();
                for(int i=0;i<8;i++)  //变总长度
                {
                    string cnt = temp;
                    for(int j=0;j<4;j++)  //改变单个字符
                    {
                        cnt[i]=a[j];
                        if(Bank.count(cnt)&&!Hash.count(cnt)) //没有提前到达过
                        {
                            if(cnt==endGene) return ret;
                            q.push(cnt);
                            Hash.insert(cnt);
                        }
                    }
                }
            }
        }
        return -1;
    }
};