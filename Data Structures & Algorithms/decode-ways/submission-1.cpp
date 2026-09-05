class Solution {
public:
    int strtoint(string s)
    {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            char a= s[i]-'0';
            ans=ans*10+a;
        }
        return ans;
    }
    int fun (string s, int idx,vector<int> &dp)
    {
        int ans=0;
        int n=s.length();
        if(idx==n)
            return 1;
        if(idx>n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        string res=""; 
        res+=s[idx];
        //int ans=0;
        int tmp=strtoint(res);
        if(tmp>=1&&tmp<=9)
        ans+=fun(s,idx+1,dp);
        if(s[idx]!='0'&&idx+1<n)
        {
            res+=s[idx+1];
            tmp=strtoint(res);
            if(tmp<=26)
                ans+=fun(s,idx+2,dp);
        }
        return dp[idx]=ans;
        

    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return fun(s,0,dp);
    }
};
