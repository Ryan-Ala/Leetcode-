class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int sum = 0;
        stack<int> sta;
        int a, b;
        for (auto& e : tokens)
        {
            if (e == "+" || e == "-" || e == "*" || e == "/")
            {
                a = sta.top();
                sta.pop();
                b = sta.top();
                sta.pop();
                switch (e[0])
                {
                case '+':
                    sta.push(a + b);
                    break;
                case '-':
                    sta.push(b - a);
                    break;
                case '*':
                    sta.push(a * b);
                    break;
                case '/':
                    sta.push(b / a);
                    break;
                default:break;
                }
            }
            else
                sta.push(stoi(e));
        }
        return sta.top();
    }
};