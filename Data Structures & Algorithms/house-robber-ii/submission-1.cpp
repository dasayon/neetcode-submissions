#include<bits/stdc++.h>
class Solution {
public:
    int dp[105];
    int fun(vector<int>& nums,int idx,int end)
    {
        if(idx>end)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];

        return dp[idx]= max(nums[idx]+fun(nums,idx+2,end),fun(nums,idx+1,end));
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        memset(dp,-1,sizeof(dp));
        int a=fun(nums,0,nums.size()-2);
        memset(dp,-1,sizeof(dp));
        return max(a,fun(nums,1,nums.size()-1));
    }
};
