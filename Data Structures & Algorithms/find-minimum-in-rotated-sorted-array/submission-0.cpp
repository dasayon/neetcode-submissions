class Solution {
public:
    int findMin(vector<int> &arr) {
        int n=arr.size();
        int piv=n-1;
        for(int i=0;i<n-1;i++)
            if(arr[i+1]<arr[i])
                piv=i;
        if(piv==n-1)
            return arr[0];
        else
            return arr[piv+1];

    }
};
