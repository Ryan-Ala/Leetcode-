class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto& e : stones)
            q.push(e);

        while (q.size() > 1)
        {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            if (a != b)
                q.push(abs(a - b));
        }
        if (q.size() == 1)
            return q.top();
        return 0;
    }
};