class Solution {
public:
    
    int fun(int idx, int state,vector<int>& prices,vector<vector<int>>& dp)
    {
        int n=prices.size();
        int ans=0;
        if(idx>=n)
            return 0;
        if(dp[idx][state]!=-1)
            return dp[idx][state];
        
        if(state)
        {
            ans=max(prices[idx]+fun(idx+2,1-state,prices,dp),fun(idx+1,state,prices,dp));
        }
        else
        {
            ans=max(fun(idx+1,1-state,prices,dp)-prices[idx],fun(idx+1,state,prices,dp));
        }
        return dp[idx][state]=ans;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,0,prices,dp);
        }
};