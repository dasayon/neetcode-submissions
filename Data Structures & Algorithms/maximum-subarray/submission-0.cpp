class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int currmax=nums[0];
            int maxres=nums[0];

            for(int i=1;i<nums.size();i++)
                {
                    currmax=max(nums[i],currmax+nums[i]);
                    maxres=max(currmax,maxres);
                }
            return maxres;
    }
};
