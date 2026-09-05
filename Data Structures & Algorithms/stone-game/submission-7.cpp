class Solution {
public:
    int fun(vector<int>& piles,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int even = ((j-i)%2==1);
        int left = even ? piles[i]:0;
        int right =even ? piles[j]:0;
        return dp[i][j]=max(left+fun(piles,i+1,j,dp),right+fun(piles,i,j-1,dp));
    }
    bool stoneGame(vector<int>& piles) 
    {
        int i=0;
        int n=piles.size();
        vector<vector<int>> dp(n,(vector<int>(n,-1)));
        int ans = fun(piles,0,n-1,dp); 
        int total =0;
        for(int i=0;i<piles.size();i++)
            total+=piles[i];
        if(ans>total-ans)
            return true;
        else
            return false;
    }
};