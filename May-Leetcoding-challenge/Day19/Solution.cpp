class StockSpanner {
    stack<int> pr, wght;
public:
    StockSpanner() {        
    }
    
    int next(int price) {
        int init_w = 1;
        while(!pr.empty() && pr.top()<=price)
        {
            pr.pop();
            init_w += wght.top();
            wght.pop();
        }
        
        pr.push(price);
        wght.push(init_w);
        return init_w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
