class Solution {
public:
    bool isPalindrome(string s,int start, int end)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        
        return true;

    }
    void backtrack(string s, int idx, vector<string> &curr, vector<vector<string>> &res)
    {
        int n=s.length();

        if(idx==n)
        {
            res.push_back(curr);
            return;        
        }
        for(int i=idx;i<n;i++)
        {
            if(isPalindrome(s,idx,i))
                {
                    curr.push_back(s.substr(idx,i-idx+1));
                    backtrack(s,i+1,curr,res);
                    curr.pop_back();
                }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr; 
        vector<vector<string>> res;

        backtrack(s,0,curr,res);
        return res;
    }
};
