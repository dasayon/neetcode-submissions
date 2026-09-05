class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);

        for(int idx=1;idx<=n;idx++)
        {
            for(int j=1;j<idx;j++)
                {
                    int a=max(j,dp[j]);
                    int b=max(idx-j,dp[idx-j]);
                    dp[idx]=max(dp[idx],a*b);
                }
        }
        for(int i=1;i<=n;i++)
            cout<<i<<" "<<dp[i]<<endl;
        return dp[n];
    }
};