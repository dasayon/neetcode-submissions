class Solution {
public:
    vector<vector<int>> res;
    void fun(vector<int> &nums,int idx,int target, vector<int> &subset)
    {
        if(idx==nums.size()||target<0)
           return;
        if(target == 0)
        {
            res.push_back(subset);
            return;
        }
           
        subset.push_back(nums[idx]);
        fun(nums,idx,target-nums[idx],subset);
        subset.pop_back();
        fun(nums,idx+1,target,subset);
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        vector<int> subset;
        //sort(nums.begin(),nums.end());
        fun(nums,0,target,subset);
        return res;
    }
};
