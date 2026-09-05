class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> res;

        int curr_start=intervals[0][0];
        int curr_end=intervals[0][1];
        vector<int> tmp(2,0);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=curr_end)
                curr_end=max(curr_end,intervals[i][1]);
            else
            {
                tmp[0]=curr_start;
                tmp[1]=curr_end;
                res.push_back(tmp);
                curr_start=intervals[i][0];
                curr_end=intervals[i][1];
            }
        }
        tmp[0]=curr_start;
        tmp[1]=curr_end;
        res.push_back(tmp);
        return res;
    }
};
