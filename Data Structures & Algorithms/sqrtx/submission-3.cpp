class Solution {
public:
    int mySqrt(int x) {
        int res=0,l=0, r=x;

        while(l<=r)
        {
            
            int mid = l+(r-l)/2;
            long long sqr = (long long)mid*mid;
            if(sqr==x)
                return mid;
            else if(sqr>x)
                r=mid-1;
            else 
                {
                    l=mid+1;
                    res=mid;
                }
        }
        return res;
    }
};