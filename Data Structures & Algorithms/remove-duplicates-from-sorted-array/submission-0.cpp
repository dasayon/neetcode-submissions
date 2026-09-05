class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i=0,j=0;
        int n=nums.size();

        while(i<n)
        {
            if(nums[i]==nums[j])
                i++;
            else
                nums[++j]=nums[i++];
                //curr=nums[j];

        }
        return j+1;
    }
};