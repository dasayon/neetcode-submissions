class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j)
            {
                int idx=(i+j)/2;
                if(nums[idx]==target)
                    return idx;
                else if (nums[idx]<target)
                    i=idx+1;
                else
                    j=idx-1;
            }
        return i;
    }
};