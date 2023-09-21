class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a, b;
        stack<int> q;
        for (auto& e : tokens)
        {
            if (e == "+" || e == "-" || e == "*" || e == "/")
            {
                a = q.top(); q.pop();
                b = q.top(); q.pop();
                switch (e[0])
                {
                case '+':
                    q.push(a + b);
                    break;
                case '-':
                    q.push(b - a);
                    break;
                case '*':
                    q.push(a * b);
                    break;
                case '/':
                    q.push(b / a);
                    break;
                default:break;
                }
            }
            else
                q.push(stoi(e));
        }
        return q.top();
    }
};