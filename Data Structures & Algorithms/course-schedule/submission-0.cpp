class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
    queue<int> Q;

    vector<int> indegree(n,0);

    for(int i=0;i<pre.size();i++)
        indegree[pre[i][1]]++;

    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            Q.push(i);
    int visited=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        visited++;
        for(int i=0;i<pre.size();i++)
           { 
                if(pre[i][0]==u)
                {
                    int v=pre[i][1];
                    indegree[v]--;
                    if(indegree[v]==0)
                        Q.push(v);
                }
           }
        
    }
    if(visited==n)
        return 1;
    else return 0;
    }
};
