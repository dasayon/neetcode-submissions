class Solution {
public:
    bool backtrack(vector<int> &arr,int k, int idx, vector<int> &sumarr,int &target)
    {
        if(idx==arr.size())
        {
            for(int i=0;i<k;i++)
            {
                if(sumarr[i]!=target)
                    return false;
            }
            return true;
        }

        for(int i=0;i<k;i++)
        {
            if(sumarr[i]+arr[idx]<=target)
                {
                    sumarr[i]+=arr[idx];
                    if(backtrack(arr,k,idx+1,sumarr,target))
                        return true;
                    sumarr[i]-=arr[idx];
                }
        }
        return false;

    }    
    
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int tot=0;
        for(int i=0;i<arr.size();i++)
            tot+=arr[i];
        if(tot%k)
            return false;
        int target= tot/k;
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        vector<int> sumarr(k,0);
        return backtrack(arr,k,0,sumarr,target);
    }

};