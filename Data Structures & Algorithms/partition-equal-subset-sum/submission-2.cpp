class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            tot+=nums[i];

        if(tot%2)
            return false;

        int target = tot/2;
        vector<vector<int>> dp (2,vector<int> (target+1,0));

        int x=1;

        dp[0][0]=1;

        for(int i=1;i<=n;i++)
           {
                for(int sum=0;sum<=target;sum++)
                {
                    dp[x][sum] = dp[1-x][sum];

                    if((sum-nums[i-1])>=0&&dp[1-x][sum-nums[i-1]])
                        dp[x][sum]=1;
                    
                }
                x=1-x;
            }   
        return dp[1-x][target];
                            
    }
};
