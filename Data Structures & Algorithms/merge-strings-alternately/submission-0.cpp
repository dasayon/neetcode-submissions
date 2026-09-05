class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int i=0,j=0;
       string ans ="";
       int n=min(word1.length(),word2.length());
    
    for(int i=0;i<n;i++)
    {
        ans+=word1[i];
        ans+=word2[i];
    }
    if(word1.length()<word2.length())
        ans+=word2.substr(n,word2.length()-1);
    else
        ans+=word1.substr(n,word1.length()-1);
    
    return ans;}
};