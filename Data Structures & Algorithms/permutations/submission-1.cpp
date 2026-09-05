class Solution {
public:
    void fun(vector<int> &nums,int idx,vector<vector<int>> &res)
    {
        int n=nums.size();
        if(idx==n)
            {
                res.push_back(nums);
                return;
            }
        if(idx>n)
            return;
        for(int i=idx;i<n;i++)
        {
            int tmp=nums[i];
            nums[i]=nums[idx];
            nums[idx]=tmp;
            fun(nums,idx+1,res);
            tmp=nums[i];
            nums[i]=nums[idx];
            nums[idx]=tmp;
        }
        return;
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        fun(nums,0,res);
        return res;
    }
};
