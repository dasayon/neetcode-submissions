class Solution {
public:
    double myPow(double x, int n) {
        double ans =1;
        if(n>0)
            while(n--)
                ans*=x;
        else
            while(n++)
                ans/=x;
        return ans;
    }
};
