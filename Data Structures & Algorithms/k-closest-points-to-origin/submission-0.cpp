class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<points.size();i++)
        {
            int dist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(pq.size()<k)
                pq.push(make_pair(dist,i));
            else if(dist<pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(dist,i));
                }
            //cout<<i<<" "<<pq.top().first<<" "<<pq.top().second<<endl;;
        }
        //priority_queue<pair<int,int>> pq :: iterator it;
        vector<vector<int>> res;
        while(!pq.empty())
        {
            pair<int,int> tmp= pq.top();
            pq.pop();
            res.push_back(points[tmp.second]);
        }
        return res;
    }
};
