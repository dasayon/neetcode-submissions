class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> M;
        for(int i=0;i<nums.size();i++)
            if(M.find(nums[i])==M.end())
                M[nums[i]]=1;
            else
                M[nums[i]]++;
    vector<pair<int,int>> v;
    map<int,int>::iterator it;
    for(it=M.begin();it!=M.end();it++)
        v.push_back(make_pair(it->second,it->first));
    sort(v.begin(),v.end());
    int n=v.size();
    vector<int> res;
    for(int i=n-k;i<n;i++)
        res.push_back(v[i].second);
    return res;
    }
};
