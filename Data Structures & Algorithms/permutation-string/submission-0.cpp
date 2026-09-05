#include<bits/stdc++.h>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length();
        int l2=s2.length();

        if(l1>l2)
            return false;
        
        int hash1[26];
        memset(hash1,0,sizeof(hash1));
        int hash2[26];
        memset(hash2,0,sizeof(hash2));
        for(int i=0;i<l1;i++)
            hash1[s1[i]-'a']++;
        for(int i=0;i<l1;i++)
            hash2[s2[i]-'a']++;

        int l=0,r=l1-1;
        int matches =0;
            for(int i=0;i<26;i++)
            {
                if (hash1[i]==hash2[i])
                    matches++;
            }
             if(matches==26)
                    return true;
        
        while(r<l2-1)
        {
            
            hash2[s2[l++]-'a']--;
            hash2[s2[++r]-'a']++;
            matches =0;
            for(int i=0;i<26;i++)
            {
                if (hash1[i]==hash2[i])
                    matches++;
            }
             if(matches==26)
                    return true;
        }
        return false;
    }
};
