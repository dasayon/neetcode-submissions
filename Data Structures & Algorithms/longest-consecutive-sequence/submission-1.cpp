class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> S(nums.begin(),nums.end());
      
       int tmp,ans=0;
       for(int num:nums)
       {
        if(S.find(num-1)==S.end())
            {
                tmp=1;
                while(S.find(num+tmp)!=S.end())
                    tmp++;
                ans=max(ans,tmp);   
            }
           
       }
       return ans;
    }
};
