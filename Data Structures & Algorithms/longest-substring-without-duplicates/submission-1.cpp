#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash,-1,sizeof(hash));

        int curr_start=0;
        int curr_max=0;
        for(int i=0;i<s.length();i++)
        {
            int idx=hash[s[i]];
           
            if(idx>=curr_start)
                curr_start=idx+1;
            curr_max=max(curr_max,i-curr_start+1);
            hash[s[i]]=i;
        }
        return curr_max;
    }
};

