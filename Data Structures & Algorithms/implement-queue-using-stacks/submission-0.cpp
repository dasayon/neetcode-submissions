class MyQueue {
public:
    stack<int> S1;
    stack<int> S2;
    MyQueue() {
        S1 ={};
        S2= {};
    }
    
    void push(int x) {
        S1.push(x);
    }
    
    int pop() {
        int ans;
        while(!S1.empty())
        {
            S2.push(S1.top());
            S1.pop(); 
        }
        ans=S2.top();
        S2.pop();
        while(!S2.empty())
        {
            S1.push(S2.top());
            S2.pop(); 
        }
        return ans;

    }
    
    int peek() {
        int ans;
        while(!S1.empty())
        {
            S2.push(S1.top());
            S1.pop(); 
        }
        ans=S2.top();
        //S2.pop();
        while(!S2.empty())
        {
            S1.push(S2.top());
            S2.pop(); 
        }
        return ans;
    }
    
    bool empty() {
        return S1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */