class Solution {
public:
    int sum1,sum2,sum3,sum4;

    bool backtrack(vector<int>& matchsticks,int idx,int target)
    {
        if(idx==matchsticks.size())
            return(sum1==target&&sum2==target&&sum3==target&&sum4==target);
        
        if(sum1+matchsticks[idx]<=target)
        {
            sum1+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target))
                return true;
            sum1-=matchsticks[idx];
        }

        if(sum2+matchsticks[idx]<=target)
        {
            sum2+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target))
                return true;
            sum2-=matchsticks[idx];
        }

        if(sum3+matchsticks[idx]<=target)
        {
            sum3+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target))
                return true;
            sum3-=matchsticks[idx];
        }

        if(sum4+matchsticks[idx]<=target)
        {
            sum4+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target))
                return true;
            sum4-=matchsticks[idx];
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
        sum1=sum2=sum3=sum4=0;
        
        return backtrack(matchsticks,0,target);
    }
};