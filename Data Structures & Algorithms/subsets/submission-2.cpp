class Solution {
public:
    void fun(int idx,vector<int>& nums, vector<int> &curr, vector<vector<int>> &res)
    {
        if(idx==nums.size())
            {
                res.push_back(curr);
                return;
            }
        fun(idx+1,nums,curr,res);
        curr.push_back(nums[idx]);
        fun(idx+1,nums,curr,res);
        curr.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        fun(0,nums,curr,res);
        return res;
    }
};
