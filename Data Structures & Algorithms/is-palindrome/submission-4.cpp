class Solution {
public:
    bool isValid(string s, int idx)
    {
        if(s[idx]>=65&&s[idx]<=90||s[idx]>=97&&s[idx]<=122||s[idx]>=48&&s[idx]<=57)
            return 1;
        return 0;
    }
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
        while(!isValid(s,i)&&i<n-1)
            i++;
        while(!isValid(s,j)&&j>0)
            j--;
        if(i<j&&tolower(s[i])!=tolower(s[j]))
            return 0;
        else
            {
                i++;j--;
            }
        }
        return 1;
    }
};
