class Solution {
public:
    bool fun(string s,int idx,unordered_set<string> S, vector<int> &dp ) 
    {
        if(idx==-1)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        for(int i=0;i<=idx;i++)
        {
            string a = s.substr(i,idx-i+1);
            if(S.contains(a))
                if(fun(s,i-1,S,dp))
                    return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> S;

        for(int i=0;i<wordDict.size();i++)
            S.insert(wordDict[i]);
        int n=s.length();
        vector<int> dp(n,-1);
        return fun(s,n-1,S,dp);
    }
};
