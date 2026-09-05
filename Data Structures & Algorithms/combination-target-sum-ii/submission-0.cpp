class Solution {
public:
    void fun(int idx,int target,vector<int>& candidates,vector <int> &curr,vector<vector<int>> &res)
    {
        int n= candidates.size();
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(idx>=n||target<0)
            return;
        curr.push_back(candidates[idx]);
        fun(idx+1,target-candidates[idx],candidates,curr,res);
        curr.pop_back();
        int k=idx+1;
        while(k<n&&candidates[k]==candidates[idx])
            k++;
        
        fun(k,target,candidates,curr,res);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> res;

        fun(0,target,candidates,curr,res);
        return res;
    }
};
