class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> S;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=0;i<temperatures.size();i++)
        {
            
            while(!S.empty()&&temperatures[i]>S.top().first)
            {
                pair<int,int> t = S.top();
                res[t.second]=i-t.second;
                S.pop();
            }
            S.push(make_pair(temperatures[i],i));
        }
        return res;
    }
};
