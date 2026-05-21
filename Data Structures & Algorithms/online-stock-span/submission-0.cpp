class StockSpanner {
public:
    vector<pair<int,int>> days;

    StockSpanner() {
    }
    
    int next(int price) {
        
        int count=1;

        while(!days.empty() && days.back().first <= price){
            count+= days.back().second;
            days.pop_back();
            
            //since consecutive ones will be thrown out so we
            //agglomerate via the count, this way suppose 80 comes first
            //then 90, 80 is counted together with 90 because only
            //when >90 comes both consecutives are popped out and span
            //of that price becomes 3- {93, 90, 80} otherwise if >80 & <90
            //then that is not consecutive anymore, {85, 90, 80} 
        }
        
        days.push_back({price, count});
        return count;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */