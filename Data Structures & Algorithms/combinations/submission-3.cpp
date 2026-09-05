class Solution {
public:
    void backtrack(int idx, int k, int n,vector<int> &curr,vector<vector<int>> &res)
    {
        if(k==0)
            {
                res.push_back(curr);
                return;
            }
        if(idx>n)
            return;
        curr.push_back(idx);
        backtrack(idx+1,k-1,n,curr,res);
        curr.pop_back();
        backtrack(idx+1,k,n,curr,res);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(1,k,n,curr,res);
        return res;
    }
};