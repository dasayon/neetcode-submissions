#include<bits/stdc++.h>
class Solution {
public:
    int fun(vector<int>& prices, int i,bool s,vector<vector<int>> &dp)
    {
        int n=prices.size();
        if(i>=n)
            return 0;
        if(dp[i][s]!=-1)
            return dp[i][s];
        int ans=0;
        if(s) // present, either sell or move on
            ans= max(fun(prices,i+2,1-s,dp)+prices[i],fun(prices,i+1,s,dp));
        else  //buy or move on
            ans = max(fun(prices,i+1,1-s,dp)-prices[i],fun(prices,i+1,s,dp));
        return dp[i][s]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(prices,0,0,dp);
    }
};
