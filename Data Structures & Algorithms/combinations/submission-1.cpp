class Solution {
public:
    void fun(int idx,int k,int n,vector<int> &curr,vector<vector<int>> &res)
    {
        
        if(k==0)
            {
                res.push_back(curr);
                return;
            }
        if(idx>n)
            return;
        curr.push_back(idx);
        fun(idx+1,k-1,n,curr,res);
        curr.pop_back();
        fun(idx+1,k,n,curr,res);
        return;
        
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> curr;

        fun(1,k,n,curr,res);
        return res;
    }
};