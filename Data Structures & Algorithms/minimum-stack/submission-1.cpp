class MinStack {
public:
    stack<int> main;
    stack<int> helper;
    MinStack() {
       //main.clear();
       //helper.clear(); 
    }
    
    void push(int val) {
        main.push(val);
        if(helper.empty())
            helper.push(val);
        else if(val<=helper.top())
        {
            helper.push(val);
        }
        
    } 
    
    void pop() {
        if(main.top()==helper.top())
            helper.pop();
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        if(helper.empty())
            return main.top();
        else
        return helper.top();
    }
};
