class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            int a = (i+j)/2;
            if(nums[a]==target)
                return a;
            if (nums[a]<target)
                i=a+1;
            else
            j=a-1;
        }
        return -1;
    }
};
