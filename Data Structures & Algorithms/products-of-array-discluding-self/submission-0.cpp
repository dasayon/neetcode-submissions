class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int>left(n,1);
        vector<int>right(n,1);
        left[1]=nums[0];
        right[n-2]=nums[n-1];

        for(int i=2;i<n;i++)
            left[i]=left[i-1]*nums[i-1];
        for(int j=n-3;j>=0;j--)
            right[j]=right[j+1]*nums[j+1];

        for(int i=0;i<n;i++)
            left[i]*=right[i];

        return left;
    }
};
