class Solution {
public:
    vector<vector<int>> res;
    void fun(vector<int> &nums,int idx,vector<int> &curr)
    {
        if(idx==nums.size())
        {
            res.push_back(curr);
            return;        
        }
        curr.push_back(nums[idx]);
        fun(nums,idx+1,curr);
        curr.pop_back();
        int i=idx;
        while(i<nums.size()&&nums[i]==nums[idx])
            i++;
        fun(nums,i,curr);
        return;
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        res.clear();
        fun(nums,0,curr);
        return res;
    }
};
