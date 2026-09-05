class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0,j=n-1;

        while(i<j)
        {
            if(arr[i]+arr[j]==target)
            {
                vector<int> res;
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(arr[i]+arr[j]<target)
                i++;
            else 
                j--;
        }

    }
};
