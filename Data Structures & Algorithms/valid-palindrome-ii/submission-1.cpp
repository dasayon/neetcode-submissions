class Solution {
public:
    bool isPalindromeHelper(string s,int start,int end)
    {
        while(start<end)
            {
                if(s[start]!=s[end])
                    return false;
                start++;
                end--;
            }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return isPalindromeHelper(s,i+1,j)||isPalindromeHelper(s,i,j-1);
            i++;
            j--;
        }
        return true;
    }
};