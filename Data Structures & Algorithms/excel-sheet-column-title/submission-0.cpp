class Solution {
public:
    string convertToTitle(int n) {
        string ans="";

        while(n)
        {
          int a=n%26;
          if(a==0)
          {
            ans+='Z';
            n=n/26-1;
          }
          else
          {
            ans+='A'+a-1;
            n/=26;
          }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};