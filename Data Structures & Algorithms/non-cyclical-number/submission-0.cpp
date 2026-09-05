class Solution {
public:
    bool isHappyHelper(int n,map<int,int> &M)
    {
        if(n==1)
            return 1;
        //cout<<M[n]<<endl;
        if(M.find(n)!=M.end())
            return 0;
        M.insert({n,1});
        int ans=0;
        while(n)
        {
            int tmp=n%10;
            ans+=tmp*tmp;
            n/=10;
        }
        
        return isHappyHelper(ans,M);
    }
    bool isHappy(int n) {
        map<int,int> M;
        return isHappyHelper(n,M);
    }
};
