class Solution {
public:    

    bool backtrack(vector<int>& matchsticks,int idx,int target,vector<int> &sumarr)
    {
        if(idx==matchsticks.size())
        {
            for(int i=0;i<4;i++)
            {
                if(sumarr[i]!=target)
                    return false;
            }
            return true;
        }

        for(int i=0;i<4;i++)
        {
            if(sumarr[i]+matchsticks[idx]<=target)
            {
                sumarr[i]+=matchsticks[idx];
                if(backtrack(matchsticks,idx+1,target,sumarr))
                    return true;
                sumarr[i]-=matchsticks[idx];
            }
        }
        
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        int tot=0;
        for(int i=0;i<matchsticks.size();i++)
            tot+=matchsticks[i];
        if(tot%4)
            return false;
        int target=tot/4;
        sort(matchsticks.begin(),matchsticks.end());
        reverse(matchsticks.begin(),matchsticks.end());
        vector<int> sumarr(4,0);
        return backtrack(matchsticks,0,target,sumarr);
    }
};