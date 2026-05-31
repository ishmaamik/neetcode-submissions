class MyCircularQueue {
public:

    vector<int> arr;
    int count, rear, front, capacity;

    MyCircularQueue(int k) {
        arr.resize(k);
        rear=-1;
        front=0;
        capacity=k;
        count=0;
    }
    
    bool enQueue(int value) {
        if(count==capacity) return false;

        rear= (++rear) % capacity;
        // this line is enough, it just replaces old dequeued value by modulo-ing with +1

        arr[rear]= value;

        count++;

        return true;
    }
    
    bool deQueue() {
        if(count==0) return false;

        front= (++front) % capacity;

        count--;

        return true;
    }
    
    int Front() {
       if(!isEmpty()) return arr[front];
       return -1;
    }
    
    int Rear() {
       if(!isEmpty()) return arr[rear];
       return -1;
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */