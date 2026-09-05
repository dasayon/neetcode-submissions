class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int n=arr.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++)
        {
            if(i>0&&arr[i]==arr[i-1])
                continue;
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=arr[i]+arr[l]+arr[r];

               if(sum==0)
               {
                    vector<int> tmp={arr[i],arr[l],arr[r]};
                    res.push_back(tmp);
                    l++;
                    r--;
                    while(l<r&&arr[l]==arr[l-1])
                        l++;
                    while(r>l&&arr[r]==arr[r+1])
                        r--;
               }
            
                else if (sum<0)
                    l++;
                else
                    r--;
            }

        }
        return res;
    }
};
