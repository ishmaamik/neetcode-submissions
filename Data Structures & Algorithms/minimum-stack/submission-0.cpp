class MinStack {
public:

    vector<vector<long long>> stack;
    //Instead of maintaining a global minimum everytime, do always with comparing min to stack.back()[1] instead
    MinStack() {
            
    }
    
    void push(int val) {
        long long min_val= stack.empty() ? (long long) val : min((long long) val, stack.back()[1]);
        stack.push_back({(long long) val, min_val});
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back()[0];
    }
    
    int getMin() {
        return stack.back()[1];
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