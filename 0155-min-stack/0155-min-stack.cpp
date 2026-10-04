class MinStack {
public:
    stack<int> s;
    stack<int> mn;

    MinStack() {
    }

    void push(int value) {
        s.push(value);

        if(mn.empty() || value <= mn.top()) {
            mn.push(value);
        }
    }

    void pop() {
        if(s.top() == mn.top()) {
            mn.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mn.top();
    }
};