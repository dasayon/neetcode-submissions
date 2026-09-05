class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> mh;
    int m;
    KthLargest(int k, vector<int>& nums) {
        mh=priority_queue<int,vector<int>,greater<int>>();
        m=k;
        for(int i=0;i<nums.size();i++)
        {
            if(mh.size()<k)
                mh.push(nums[i]);
            else if(nums[i]>mh.top())
            {
                mh.pop();
                mh.push(nums[i]);
            }
        }    
    }
    
    int add(int val) {
        if(mh.size()<m)
            mh.push(val);
        else if(val>mh.top())
            {
                mh.pop();
                mh.push(val);
                //return mh.top();
            }
       
        return mh.top();
    }
};
