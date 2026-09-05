class StockSpanner {
public:
    stack<pair<int,int>> S;
    int idx;
    StockSpanner() {
        S=stack<pair<int,int>>();
        idx=0;
    }
    
    int next(int price) {
        int x=0;
        idx++;
        cout<<idx<<" "<<price<<endl;
        if(S.empty()||price<S.top().first)
        {
            S.push({price,idx});
            return 1;         
        }
        else
        {
            while(!S.empty()&&S.top().first<=price)
                S.pop();
            if(!S.empty())
                x=S.top().second;
            S.push({price,idx});
            return idx-x;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */