class Solution {
public:
    vector<string> res;
    map<int,string> M ={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void fun(string digits,int idx,string curr)
    {
        int n=digits.length();
        if(idx==n)
            {
                res.push_back(curr);
                return;
            }
        string t=M[digits[idx]-48];
        for(int i=0;i<t.length();i++)
        {
            curr+=t[i];
            fun(digits,idx+1,curr);
            curr.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        
        res.clear();
        if(digits.length()==0)
            return res;
        string curr;
        fun(digits,0,curr);
        return res;
        
    }
};
