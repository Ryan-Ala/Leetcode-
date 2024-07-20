class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int m = pushed.size();
        int push = 0,pop = 0;
        while(push<m)
        {
            while(s.size()==0||s.top()!=popped[pop])
            {
                if(push<m)
                s.push(pushed[push++]);
                else
                return 0;
            }
            while(s.size()!=0&&s.top()==popped[pop])
            {
                s.pop();
                pop++;
            }
        }
        if(push==m&&s.size()==0)
        return 1;
        return 0;
    }
};