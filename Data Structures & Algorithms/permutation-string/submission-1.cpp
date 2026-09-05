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
            
            int idx=s2[l]-'a';

            hash2[idx]--;
            //After reducing if it is equal now
            if(hash2[idx]==hash1[idx])
                matches++;
            else if(hash2[idx]+1==hash1[idx]) //if earlier it was a match, before increment
                matches--;
            l++;
            r++;
            idx =s2[r]-'a';
            hash2[idx]++;
            if(hash2[idx]==hash1[idx])
                matches++;
            else if (hash2[idx]-1==hash1[idx])
                matches--;
             if(matches==26)
                    return true;
        }
        return false;
    }
};
