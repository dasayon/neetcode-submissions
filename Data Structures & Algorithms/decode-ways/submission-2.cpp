class Solution {
public:

    int fun(string s, int idx, vector<int> &dp)
    {
        int n=s.length();
        //cout<<idx<<endl;
        if(idx>n||s[idx]=='0')
            return 0;
        if(idx==n)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        int a=0;
        if(idx+1<n&&s[idx]!='0')
            {
                a=(s[idx]-'0')*10+(s[idx+1]-'0');
                
                if(a<=26)
                    ans+=fun(s,idx+2,dp);
            }
        ans+=fun(s,idx+1,dp);
        return dp[idx]=ans;
        
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,-1);

        fun(s,0,dp);;
        return max(0,dp[0]);   
    }
};
