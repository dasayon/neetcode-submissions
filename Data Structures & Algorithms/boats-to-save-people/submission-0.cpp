class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int count=0;
        int i=0,j=n-1;

        while(i<=j)
        {
            count++;
            if(i==j)
            break;
            if(arr[i]+arr[j]<=limit)
            {
                
                i++;
                j--;
            }
            else 
                j--;

        }
        return count;
    }
};