class Solution {
public:
    void fun (int left,int right, string &curr, vector<string> &res)
    {
        if(left>right)
            return;
        if(left==0&&right==0)
            {
                res.push_back(curr);
                return;
            }
        if(left>0)
            {
                curr+='('; 
                fun(left-1,right,curr,res);
                curr.pop_back();
            }
        if(right>0)
        {
            curr+=')';
            fun(left,right-1,curr,res);
            curr.pop_back();
        }        
        return;
    }
    vector<string> generateParenthesis(int n) {
       string curr="";
       vector<string> res;
       fun(n,n,curr,res);
       return res;
    }
};
