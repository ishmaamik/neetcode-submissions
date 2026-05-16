class MyStack {
public:

    queue<int> q1;
    queue<int> q2;

    MyStack() {

    }
    
    void push(int x) {

        q2.push(x);

        while(!q1.empty()){
            int y= q1.front();
            q1.pop();
            q2.push(y);
        }

        swap(q1, q2); // suppose q1= 1, q2=2 so now push 1 to q2, q2= 2,1 now swap
        //q1= 2,1. Next q2=3, push q1 into q2 now q2= 3,2,1. swap now q1= 3,2,1.    
    }
    
    int pop() {
        int y= q1.front();
        q1.pop();
        return y;
    }
    
    int top() {
        int y= q1.front();
        return y;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */