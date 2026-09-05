class Solution {
public:
    void fun(vector<int> nums,int target, int idx,vector<int> &curr,vector<vector<int>> &res)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        int n=nums.size();
        if(idx>=n||target<0)
            return;
        curr.push_back(nums[idx]);
        fun(nums,target-nums[idx],idx,curr,res);
        curr.pop_back();
        fun(nums,target,idx+1,curr,res);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        fun(nums,target,0,curr,res);
        return res;
    }
};
