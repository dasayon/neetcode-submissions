/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans,mid,l=1,r=n;

        while(l<=r)
        {
            if(l==r)
                return l;
            mid=l+(r-l)/2;
            ans=guess(mid);
            if(ans==0)
                return mid;
            else if (ans<0)
                r=mid-1;
            else 
                l=mid+1;
        }
    return -1;
    }
};