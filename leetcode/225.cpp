class MyStack {
public:
    queue<int> q;
    MyStack() {
        q = queue<int>();
    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int ret = q.back();
        for (int i = 0; i < q.size() - 1; i++) {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        q.pop();
        return ret;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */