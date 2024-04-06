class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> Hash;
        unordered_set<char> in_stack;
        for(auto e:s)
        Hash[e]++;

        stack<char> sta;

        for(auto e:s)
        {
            Hash[e]--;
            if(in_stack.count(e))
            continue;

            while(sta.size()&&sta.top()>e) //后面还有1个以上就能pop当前的
            {
                if(Hash[sta.top()]==0)
                break;

                in_stack.erase(sta.top());
                sta.pop();
                // char a = sta.top();
                // if(Hash[a]>=1)
                // {
                //     in_stack.erase(a);
                //     sta.pop();
                // }
                // else
                // break;
            }
            sta.push(e);
            in_stack.insert(e);
        }

        string ans;
        while(sta.size())
        {
            ans+=sta.top();
            sta.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};