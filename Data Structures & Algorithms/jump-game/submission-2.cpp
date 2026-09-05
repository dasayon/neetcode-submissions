class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>=0&&i!=0)
                continue;
            int pos=i+abs(nums[i]);
            pos=min(pos,n-1);
            for(int j=i+1;j<=pos;j++)
            {
                if(nums[j]>0)
                    nums[j]*=-1;
                else if(j==n-1)
                    nums[j]=-1;
            }
        }
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        return (nums[n-1]<0);
    }
};
