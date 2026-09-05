class Solution {
public:
    vector<vector<int>> res;
    void fun (int idx,int n,int k,vector<int> &curr)
    {
        
        if(k==0)
            {
                res.push_back(curr);
                return;
            }
        if(idx>n)
            return; 
        curr.push_back(idx);
        fun(idx+1,n,k-1,curr);
        curr.pop_back();
        fun(idx+1,n,k,curr);
        return;
        
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> curr;
        fun(1,n,k,curr);
        return res;
    }
};