class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();

        vector<vector<int>> dp(m+1,(vector<int>(n+1,0)));
        dp[0][0]=(s1[0]==s2[0]);
        
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else{
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        return dp[m][n];
    }
};
