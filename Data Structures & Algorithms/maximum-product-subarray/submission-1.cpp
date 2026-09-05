class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int prev_max=arr[0];
        int prev_min=arr[0];
        int curr_max=arr[0];
        int curr_min=arr[0];
        int global_max =arr[0];
        for(int i=1;i<arr.size();i++)
        {
            curr_max = max(arr[i],max(prev_max*arr[i],prev_min*arr[i]));
            curr_min = min(arr[i],min(prev_max*arr[i],prev_min*arr[i]));
            global_max = max(global_max,curr_max);
            prev_max=curr_max;
            prev_min=curr_min;
        }
        return global_max;
    }
};
