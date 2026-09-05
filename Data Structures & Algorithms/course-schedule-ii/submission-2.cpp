class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> res;
        int visited=0;

        vector<int> indegree(n,0);

        for(int i=0;i<pre.size();i++)
        {
            indegree[pre[i][0]]++;
        }
        queue<int> Q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                Q.push(i);
        
        while(!Q.empty())
        {
            int u=Q.front();
            //cout<<u<<endl;
            Q.pop();
            res.push_back(u);
            visited++;
            for(int i=0;i<pre.size();i++)
                {
                    if(pre[i][1]==u)
                    {
                        int v=pre[i][0];
                        indegree[v]--;
                        if(indegree[v]==0)
                            Q.push(v);
                    }
                }
        }
        if(visited==n)
            return res;
        else{
            res.clear();
            return res;
        }

    }
};
