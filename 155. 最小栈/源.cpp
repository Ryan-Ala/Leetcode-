class MinStack {
public:
    stack<int> ret;
    stack<int> min;
    MinStack() {

    }

    void push(int val) {
        if (min.empty() || min.top() >= val)
        {
            min.push(val);
        }
        ret.push(val);
    }

    void pop() {
        if (ret.top() == min.top())
            min.pop();
        ret.pop();
    }

    int top() {
        return ret.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */