class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        priority_queue<int, vector<int>, greater<int>> temp= pq;
        if(temp.size()%2==0){
            int size= temp.size()/2;

            cout<<"Even: "<<temp.size()<<" "<<endl;
            while(temp.size()!=(size+1)){   //if size() is 8 we need
                //to remove (8/2)-1 i.e. 4-1 i.e. 3 only then
                //4th & 5th are for median!
                temp.pop();
                cout<< "Size of pq now: "<<temp.size()<<endl;
            }

            double n1= temp.top();
            temp.pop();
            double n2= temp.top();
            temp.pop();

            return (n1+n2)/2.0;
        }
        else{
            int size= (temp.size()/2)+1;
            while(temp.size()!=size){
                temp.pop();
            }
            double n1= temp.top();

            return n1;
        }
    }
};