class Solution {
public:

    bool backtrack(vector<int>& matchsticks,int idx,int target,int &sum1,int &sum2,int &sum3,int &sum4)
    {
        if(idx==matchsticks.size())
            return(sum1==target&&sum2==target&&sum3==target&&sum4==target);
        //bool flag=false;
        if(sum1+matchsticks[idx]<=target)
        {
            sum1+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target,sum1,sum2,sum3,sum4))
                return true;
            sum1-=matchsticks[idx];
        }

        if(sum2+matchsticks[idx]<=target)
        {
            sum2+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target,sum1,sum2,sum3,sum4))
                return true;
            sum2-=matchsticks[idx];
        }

        if(sum3+matchsticks[idx]<=target)
        {
            sum3+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target,sum1,sum2,sum3,sum4))
                return true;
            sum3-=matchsticks[idx];
        }

        if(sum4+matchsticks[idx]<=target)
        {
            sum4+=matchsticks[idx];
            if(backtrack(matchsticks,idx+1,target,sum1,sum2,sum3,sum4))
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
        int sum1=0;
        int sum2=0;
        int sum3=0;
        int sum4=0;
        return backtrack(matchsticks,0,target,sum1,sum2,sum3,sum4);

    }
};