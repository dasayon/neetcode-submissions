class Solution {
public:
    void fun(int idx,vector<int> nums,vector<int> &subset,vector<vector<int>> &res)
    {
        if(idx==nums.size())
            {
                res.push_back(subset);
                return;
            }
        subset.push_back(nums[idx]);
        fun(idx+1,nums,subset,res);
        subset.pop_back();
        fun(idx+1,nums,subset,res);
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;
        vector<vector<int>> res;

        fun (0,nums,subset,res);
        return res;
    }
};
