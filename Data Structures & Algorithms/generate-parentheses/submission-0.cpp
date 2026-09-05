class Solution {
public:
    void fun (int left,int right, string &curr, vector<string> &res)
    {
        if(left>right)
            return;
        //if(left<0||right<0)
         //   return;
        if(left==0&&right==0)
            {
                res.push_back(curr);
                return;
            }
        if(left>0)
            {
                curr+='('; //left--;
                fun(left-1,right,curr,res);
                //left++;
                curr.pop_back();
            }
        if(right>0)
        {
            curr+=')';//right--;
            fun(left,right-1,curr,res);
            //right++;
            curr.pop_back();
        }        
        return;
    }
    vector<string> generateParenthesis(int n) {
       string curr="";
       vector<string> res;
       //int left=n;
       //int right=n;
       
       fun(n,n,curr,res);
       return res;
    }
};
