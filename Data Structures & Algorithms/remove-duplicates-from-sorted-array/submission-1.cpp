class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i=0,j=0;
        int n=nums.size();

        while(i<n)
        {
            if(nums[i]!=nums[j])
                nums[++j]=nums[i];
            i++;

        }
        return j+1;
    }
};