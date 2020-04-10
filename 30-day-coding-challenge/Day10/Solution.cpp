class MinStack {
    stack<int> main, min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        main.push(x);
        if(min.empty())
        {
            min.push(x);
        }
        else
        {
            if(min.top()>=x)
                min.push(x);            
        }
    }
    
    void pop() {
        if(!main.empty())
        {
            if(main.top()==min.top())
                min.pop();
            main.pop();            
        }
    }
    
    int top() {
        if(!main.empty())
        {
            return main.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
        {
            return min.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
