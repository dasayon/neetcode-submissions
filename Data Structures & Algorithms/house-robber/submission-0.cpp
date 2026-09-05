#include<bits/stdc++.h>
class Solution {
public:
    int dp[105];
    int fun(vector<int>& nums,int idx)
    {
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];

        return dp[idx]= max(nums[idx]+fun(nums,idx+2),fun(nums,idx+1));
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(nums,0);
    }
};
