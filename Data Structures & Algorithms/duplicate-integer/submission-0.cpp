class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        map <int,int> M;
        for (int i=0;i<nums.size();i++)
        {
            if(M.find(nums[i])!=M.end())
                return 1;
            else
            M[nums[i]]=1;
        }
        return 0;
    }
};
