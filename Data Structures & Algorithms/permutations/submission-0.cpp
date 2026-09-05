class Solution {
public:
    
    void fun(int idx,vector<int>&nums,vector<vector<int>> &res)
    {
        if(idx==nums.size()-1)
            {
                res.push_back(nums);
                return;
            }
        for(int j=idx;j<nums.size();j++)
            {
                int tmp=nums[idx];
                nums[idx]=nums[j];
                nums[j]=tmp;
                fun(idx+1,nums,res);
                tmp=nums[idx];
                nums[idx]=nums[j];
                nums[j]=tmp;
            }
        return;

        
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
         fun(0,nums,res);
        return res;
    }
};
